#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	int nb;
	cin >> nb;
	
	int nbInch = (nb + 1) / 3;
	cout << nbInch / 12 << " " << nbInch % 12 << endl;
}