#include <iostream>
using namespace std;

bool canMatch(string source, string result) {
	int iResult = 0;

	char derCar = '^';
	for(char car : source) {
		while(result[iResult] != car) {
			if(result[iResult] != derCar) return false;
			iResult++;
			if(iResult == (int)result.size()) return false;
		}
		derCar = car;
		iResult++;
	}

	while(iResult != (int)result.size()) {
		if(result[iResult] != derCar) return false;
		iResult++;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbPaires;
	cin >> nbPaires;

	for(int iPaire = 0;iPaire < nbPaires;iPaire++) {
		string a, b;
		cin >> a >> b;

		cout << (canMatch(a, b)?"YES":"NO") << endl;
	}
	return 0;
}