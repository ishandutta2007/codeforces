#include <iostream>
using namespace std;

int main() {
	int taille;
	cin >> taille;
	
	if(taille % 4 == 2 || taille % 4 == 3) {
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 0;i < taille / 2;i++) {
		if(i % 2 == 0)
			cout << i + 2 << " ";
		else
			cout << taille - i + 1 << " ";
	}
	
	if(taille % 2 == 1)
		cout << (taille + 1) / 2 << " ";
	
	for(int i = 0;i < taille / 2;i++) {
		if(i % 2 == 0)
			cout << taille / 2 - i - 1 << " ";
		else
			cout << (taille + 1) / 2 + i << " ";
	}
	
	cout << endl;
	
	return 0;
}