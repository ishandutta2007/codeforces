#include <iostream>
#include <map>
using namespace std;

map<string, string> dico;

int main() {
	int nbMots, nbDico;
	cin >> nbMots >> nbDico;
	
	for(int iDico = 0;iDico < nbDico;iDico++) {
		string a, b;
		cin >> a >> b;
		dico[a] = b;
	}
	
	for(int iMot = 0;iMot < nbMots;iMot++) {
		string mot;
		cin >> mot;
		
		if(mot.size() <= dico[mot].size()) {
			cout << mot << " ";
		}
		else {
			cout << dico[mot] << " ";
		}
	}
	cout << endl;
}