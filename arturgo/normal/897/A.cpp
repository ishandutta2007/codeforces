#include <iostream>
using namespace std;

int main() {
	int nbCars, nbOps;
	cin >> nbCars >> nbOps;
	
	string chaine;
	cin >> chaine;
	
	for(int iOp = 0;iOp < nbOps;iOp++) {
		int deb, fin;
		char a, b;
		cin >> deb >> fin >> a >> b;
		deb--;
		for(int i = deb;i < fin;i++) {
			if(chaine[i] == a)
				chaine[i] = b;
		}
	}
	
	cout << chaine << endl;
	return 0;
}