#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isDivisible(string a, string b) {
	int iCar = 0;
	
	for(char car : a) {
		if(car != b[iCar])
			return false;
		iCar = (iCar + 1) % (int)b.size();
	}
	
	return iCar == 0;
}

int main() {
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		string a, b;
		cin >> a >> b;
		
		bool hasLcm = false;
		
		string m = a;
		for(int iFois = 0;iFois < 30;iFois++) {
			if(isDivisible(m, b)) {
				cout << m << endl;
				hasLcm = true;
				break;
			}
			m = m + a;
		}
		
		if(!hasLcm)
			cout << -1 << endl;
	}
	return 0;
}