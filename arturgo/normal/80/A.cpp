#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

bool estPremier(int a) {
	for(int iDiv = 2;iDiv * iDiv <= a;iDiv++) {
		if(a % iDiv == 0)
			return false;
	}
	return true;
}

int main() {	
	int a, b;
	cin >> a >> b;
	
	if(a >= b) {
		cout << "NO" << endl;
		return 0;
	}
	if(!estPremier(a) || !estPremier(b)) {
		cout << "NO" << endl;
		return 0;
	}
	
	for(int iVal = a + 1;iVal < b;iVal++) {
		if(estPremier(iVal)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	return 0;
}