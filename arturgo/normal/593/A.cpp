#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <cmath>
using namespace std;

string mots[100];

int nbPris[100];
bool estPris[26][100];

int main()
{
	int nbMots;
	cin >> nbMots;
	
	for(int iMot = 0;iMot < nbMots;iMot++)
	{
		cin >> mots[iMot];
		for(int iCar = 0;iCar < (int)mots[iMot].size();iCar++)
			if(!estPris[mots[iMot][iCar] - 'a'][iMot])
			{
				estPris[mots[iMot][iCar] - 'a'][iMot] = true;
				nbPris[iMot]++;
			}
	}
	
	int maxTaille = 0;
	for(int iL1 = 0;iL1 < 26;iL1++)
		for(int iL2 = iL1 + 1;iL2 < 26;iL2++)
		{
			int taille = 0;
			for(int iMot = 0;iMot < nbMots;iMot++)
				if((nbPris[iMot] == 1 && (estPris[iL1][iMot] || estPris[iL2][iMot])) || (nbPris[iMot] == 2 && (estPris[iL1][iMot] && estPris[iL2][iMot])))
			{
				taille += mots[iMot].size();
			}
			maxTaille = max(taille, maxTaille);
		}
	cout << maxTaille << endl;
	return 0;
}