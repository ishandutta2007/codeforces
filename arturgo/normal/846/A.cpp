#include <iostream>
#include <algorithm>
using namespace std;

int valeurs[1000];

int compte(int deb, int fin, int val) {
	int cnt = 0;
	
	for(int i = deb; i < fin;i++) {
		if(valeurs[i] == val)
			cnt++;
	}
	
	return cnt;
}

int main() {
	int nbJeux;
	cin >> nbJeux;
	
	for(int iJeu = 0;iJeu < nbJeux;iJeu++) {
		cin >> valeurs[iJeu];
	}
	
	int maxi = 0;
	for(int iCoupe = 0;iCoupe <= nbJeux;iCoupe++) {
		maxi = max(compte(0, iCoupe, 0) + compte(iCoupe, nbJeux, 1), maxi);
	}
	
	cout << maxi << endl;
	return 0;
}