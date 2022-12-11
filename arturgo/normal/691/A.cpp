#include <iostream>
using namespace std;

int main() {
	int nbButtons;
	cin >> nbButtons;
	
	int sum = 0;
	for(int iButton = 0;iButton < nbButtons;iButton++) {
		int open;
		cin >> open;
		sum += open;
	}
	if((sum == nbButtons - 1 && nbButtons != 1) || (nbButtons == 1 && sum == 1)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}