#include <iostream>
#include <map>
using namespace std;

map<int, int> nombres;

int main() {
	int nbNombres, x;
	cin >> nbNombres >> x;
	
	long long nbPaires = 0;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int cur;
		cin >> cur;
		
		if(nombres.find(cur ^ x) != nombres.end())
			nbPaires += nombres[cur ^ x];
		
		if(nombres.find(cur) == nombres.end())
			nombres[cur] = 0;
		nombres[cur] = nombres[cur] + 1;
	}
	
	cout << nbPaires;
}