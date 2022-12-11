#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int vals[101];

int main() {
	int nbNoeuds, nbArcs;
	cin >> nbNoeuds >> nbArcs;
	
	for(int iArc = 0;iArc < nbArcs;iArc++) {
		int deb, fin, dette;
		cin >> deb >> fin >> dette;
		vals[deb] -= dette;
		vals[fin] += dette;
	}
	
	int somme = 0;
	for(int i = 0;i < 101;i++) {
		if(vals[i] >= 0)
			somme += vals[i];
	}
	
	cout << somme << endl;
}