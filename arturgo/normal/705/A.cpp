#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	bool hate = true;
	for(int iL = 0;iL < n - 1;iL++) {
		if(hate) {
			cout << "I hate that ";
		}
		else {
			cout << "I love that ";
		}
		hate = !hate;
	}
	
	if(hate) {
		cout << "I hate it";
	}
	else {
		cout << "I love it";
	}
	return 0;
}