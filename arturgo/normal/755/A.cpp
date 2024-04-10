#include <iostream>

using namespace std;

bool estPremier(int a) {
	if(a < 2)
		return false;
	for(int iDiv = 2;iDiv < a;iDiv++) {
		if(a % iDiv == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 1;i <= 1000;i++) {
		if(!estPremier(i * n + 1)) {
			cout << i << endl;
			return 0;
		}
	}
    return 0;
}