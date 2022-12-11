#include <iostream>
#include <set>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	set<string> noms;
	noms.insert(a);
	noms.insert(b);
	
	for(string nom : noms) { cout << nom << " "; } cout << endl;
	
	int nbFois;
	cin >> nbFois;
	
	for(int iFois = 0;iFois < nbFois;iFois++) {
		cin >> a >> b;
		noms.erase(a);
		noms.insert(b);
		for(string nom : noms) { cout << nom << " "; } cout << endl;
	}
}