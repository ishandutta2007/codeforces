#include <iostream>
using namespace std;

long long besoin[100 * 1000];
long long p[100 * 1000], q[100 * 1000];

int main() {
	long long nbMatieres;
	cin >> nbMatieres;
	
	for(long long iMatiere = 0;iMatiere < nbMatieres;iMatiere++) {
		long long val;
		cin >> val;
		besoin[iMatiere] -= val;
	}
	
	for(long long iMatiere = 0;iMatiere < nbMatieres;iMatiere++) {
		long long val;
		cin >> val;
		besoin[iMatiere] += val;
	}
	
	for(long long iMatiere = 1;iMatiere < nbMatieres;iMatiere++) {
		cin >> p[iMatiere] >> q[iMatiere];
		p[iMatiere]--;
	}
	
	for(long long iMatiere = nbMatieres - 1;iMatiere >= 1;iMatiere--) {
		if(besoin[iMatiere] <= 0) {
			if(besoin[p[iMatiere]] + (double)besoin[iMatiere] >= 2. * 1000 * 1000 * 1000 * 1000 * 1000 * 1000) {
				cout << "NO" << endl;
				return 0;
			}
			
			besoin[p[iMatiere]] += besoin[iMatiere];
		}
		else {
			if(besoin[p[iMatiere]] + (double)q[iMatiere] * besoin[iMatiere] >= 2. * 1000 * 1000 * 1000 * 1000 * 1000 * 1000) {
				cout << "NO" << endl;
				return 0;
			}
				
			besoin[p[iMatiere]] += q[iMatiere] * besoin[iMatiere];
		}
	}
	
	if(besoin[0] > 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	
	return 0;
}