// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BuildOrDie.h"
#include "BuildOrDieGameMode.h"
#include "BuildOrDieHUD.h"

ABuildOrDieGameMode::ABuildOrDieGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnObject(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnObject.Object != NULL)
	{
		DefaultPawnClass = (UClass*)PlayerPawnObject.Object->GeneratedClass;
	}

	// use our custom HUD class
	HUDClass = ABuildOrDieHUD::StaticClass();
}
