#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

long long nombre = 1;

long long fibo[100042];

void traite(int n) {
	nombre = (nombre * fibo[n]) % MOD;
}

signed main() {
	string chaine;
	cin >> chaine;

	fibo[0] = fibo[1] = 1;

	for(int i = 2;i < 100042;i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	}

	int taille = 0;
	char derCar = ' ';
	for(char car : chaine) {
		if(car == 'w' || car == 'm')
			nombre = 0;
		if(car == derCar) {
			taille++;
		}
		else {
			if(derCar == 'n' || derCar == 'u')
				traite(taille);
			taille = 1;
			derCar = car;
		}
	}

	if(derCar == 'n' || derCar == 'u')
		traite(taille);

	cout << nombre << endl;
	return 0;
}