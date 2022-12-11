#include <iostream>
using namespace std;

int nombresP[4004];
int nombresM[4004];

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	int tot = 0;
	for(int i = 0;i < nbNombres;i++) {
		int a, b;
		cin >> a >> b;
		tot += nombresP[2002 + a + b];
		nombresP[2002 + a + b]++;
		tot += nombresM[2002 + a - b];
		nombresM[2002 + a - b]++;
	}
	
	cout << tot << endl;
	return 0;
}