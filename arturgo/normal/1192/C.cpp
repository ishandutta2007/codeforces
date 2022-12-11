#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

set<string> mots;

long long nbEntre[11][62][62];
long long nbTriforces[11][62][62][62];

int toId(char car) {
	if(car >= 'a' && car <= 'z')
		return car - 'a';
	if(car >= 'A' && car <= 'Z')
		return 26 + car - 'A';
	return 52 + car - '0';
}

int coeff(int idA, int idB, int idC, int idD) {
	if(idA != idB && idB != idC && idC != idD)
		return 24;
	if(idA == idB && idB != idC && idC != idD)
		return 12;
	if(idA != idB && idB == idC && idC != idD)
		return 12;
	if(idA != idB && idB != idC && idC == idD)
		return 12;
	if(idA == idB && idB != idC && idC == idD)
		return 6;
	if(idA == idB && idB == idC && idC == idD)
		return 1;
	return 4;
}

int main() {
	ios_base::sync_with_stdio(false);

	int nbMots;
	cin >> nbMots;

	for(int iMot = 0;iMot < nbMots;iMot++) {
		string mot;
		cin >> mot;

		mots.insert(mot);
		reverse(mot.begin(), mot.end());
		mots.insert(mot);
	}

	for(string mot : mots) {
		nbEntre[mot.size()][toId(mot[0])][toId(mot.back())]++;
	}

	for(int taille = 3;taille <= 10;taille++) {
		for(int idA = 0;idA < 62;idA++) {
			for(int idB = idA;idB < 62;idB++) {
				for(int idC = idB;idC < 62;idC++) {
					for(int pivot = 0;pivot < 62;pivot++) {
						nbTriforces[taille][idA][idB][idC] = (nbTriforces[taille][idA][idB][idC] +
							nbEntre[taille][idA][pivot]
							* ((nbEntre[taille][idB][pivot]
							* nbEntre[taille][idC][pivot]) % MOD)) % MOD;
					}
				}
			}
		}
	}

	long long nbSolutions = 0;

	for(int taille = 3;taille <= 10;taille++) {
		for(int idA = 0;idA < 62;idA++) {
			for(int idB = idA;idB < 62;idB++) {
				for(int idC = idB;idC < 62;idC++) {
					for(int idD = idC;idD < 62;idD++) {
						nbSolutions = (
							nbSolutions + coeff(idA, idB, idC, idD) * ((
							((nbTriforces[taille][idA][idB][idC] * nbTriforces[taille][idA][idB][idD]) % MOD)
							*
							((nbTriforces[taille][idA][idC][idD] * nbTriforces[taille][idB][idC][idD]) % MOD)
						) % MOD))
						% MOD;
					}
				}
			}
		}
	}

	cout << nbSolutions << endl;
	return 0;
}