#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sommes[(1 << 18)];

void modifie(int pos, int val) {
	pos += (1 << 17);
	
	while(pos != 0) {
		sommes[pos] += val;
		pos /= 2;
	}
}

int getSomme(int deb, int fin) {
	deb += (1 << 17);
	fin += (1 << 17);
	
	int somme = 0;
	while(deb < fin) {
		if(deb % 2 == 1) {
			somme += sommes[deb];
			deb++;
		}
		if(fin % 2 == 1) {
			fin--;
			somme += sommes[fin];
		}
		deb /= 2;
		fin /= 2;
	}
	
	return somme;
}

int nbCartes;
vector<int> positions[200 * 1000];

int main() {
	cin >> nbCartes;
	
	for(int iCarte = 0;iCarte < nbCartes;iCarte++) {
		int val;
		cin >> val;
		positions[val].push_back(iCarte);
		
		modifie(iCarte, 1);
	}
	
	int curPos = 0;
	
	long long nbEtapes = 0;
	for(int iVal = 0;iVal < 200 * 1000;iVal++) {
		if(positions[iVal].empty())
			continue;
		sort(positions[iVal].begin(), positions[iVal].end());
		
		int derAvant = -1;
		while(
			derAvant + 1 != (int)positions[iVal].size()
		&&	positions[iVal][derAvant + 1] < curPos
		) {
			derAvant++;
		}
		
		int nouvPos;
		if(derAvant == -1) {
			nouvPos = positions[iVal].back();
			nbEtapes += getSomme(curPos, nouvPos + 1);
		}
		else {
			nouvPos = positions[iVal][derAvant];
			nbEtapes += getSomme(curPos, nbCartes);
			nbEtapes += getSomme(0, nouvPos + 1);
		}
		
		for(int pos : positions[iVal]) {
			modifie(pos, -1);
		}
		curPos = nouvPos;
	}
	
	cout << nbEtapes << endl;
}