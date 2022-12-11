#include <iostream>
using namespace std;

int grille[1000][1000];

int main() {
	int n, k;
	cin >> n >> k;
	
	int cur = n * n;
	for(int iLig = 0;iLig < n;iLig++) {
		for(int iCol = n - 1;iCol >= k - 1;iCol--) {
			grille[iLig][iCol] = cur--;
		}
	}
	
	for(int iLig = 0;iLig < n;iLig++) {
		for(int iCol = k - 2;iCol >= 0;iCol--) {
			grille[iLig][iCol] = cur--;
		}
	}
	
	int somme = 0;
	for(int iLig = 0;iLig < n;iLig++)
		somme += grille[iLig][k - 1];
	cout << somme << endl;
	
	for(int iLig = 0;iLig < n;iLig++) {
		for(int iCol = 0;iCol < n;iCol++) {
			cout << grille[iLig][iCol] << " ";
		}
		cout << endl;
	}
	return 0;
}