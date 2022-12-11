#include <iostream>
using namespace std;

int main() {
	long long nbJoueurs;
	cin >> nbJoueurs;
	
	long long der = 1, cur = 2;
	int nb = 0;
	while(cur <= nbJoueurs) {
		long long t = cur;
		cur = t + der;
		der = t;
		nb++;
	}
	cout << nb << endl;
	return 0;
}