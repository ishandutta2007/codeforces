#include <iostream>
using namespace std;

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	long long somme = 0;
	int mini = 1000 * 1000 * 1000;
	for(int i = 0;i < nbNombres;i++) {
		int n;
		cin >> n;
		somme += n;
		if(n % 2 == 1)
			mini = min(mini, n);
	}
	
	if(somme % 2 == 1)
		cout << somme - mini << endl;
	else
		cout << somme << endl;
	return 0;
}