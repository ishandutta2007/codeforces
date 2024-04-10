#include <iostream>
using namespace std;

int main() {
	int yolo;
	cin >> yolo;
	
	for(int iSwag = 0;iSwag < yolo;iSwag++) {
		int unicorn;
		cin >> unicorn;
		
		if(unicorn == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	cout << 1 << endl;
	return 0;
}