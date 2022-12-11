#include <iostream>
using namespace std;

int main() {
	int taille, nbInter;
	cin >> taille >> nbInter;
	
	int minDist = 1000 * 1000;
	
	for(int iInter = 0;iInter < nbInter;iInter++) {
		int a, b;
		cin >> a >> b;
		
		minDist = min(minDist, b - a + 1);
	}
	
	cout << minDist << endl;
	
	for(int i = 0;i < taille;i++) {
		cout << i % minDist << " ";
	}
	cout << endl;
}