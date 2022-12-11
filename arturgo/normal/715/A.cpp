#include <iostream>
using namespace std;

int main() {
	long long nbFois;
	cin >> nbFois;
	
	cout << 2 << endl;
	for(long long iFois = 2;iFois <= nbFois;iFois++) {
		cout << iFois * (iFois + 1) * (iFois + 1) - (iFois - 1) << endl;
	}
	return 0;
}