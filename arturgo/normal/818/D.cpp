#include <iostream>
#include <vector>
using namespace std;

vector<int> seqs[1000 * 1000];

bool comp(int a, int b) {
	if(seqs[a].size() < seqs[b].size())
		return false;
	
	for(int iVal = 0;iVal < (int)seqs[b].size();iVal++) {
		if(seqs[a][iVal] > seqs[b][iVal]) {
			return false;	
		}
	}
	
	return true;
}

int main() {
	int nbCartes, alice;
	cin >> nbCartes >> alice;
	alice--;
	
	for(int iCarte = 0;iCarte < nbCartes;iCarte++) {
		 int val;
		 cin >> val;
		 val--;
		 
		 seqs[val].push_back(iCarte);
	}
	
	for(int iCouleur = 0;iCouleur < 1000 * 1000;iCouleur++) {
		if(iCouleur != alice && comp(iCouleur, alice)) {
			cout << iCouleur + 1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}