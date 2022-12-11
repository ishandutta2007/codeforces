#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int n;
	cin >> n;
	
	int max = 0;
	for(int i = 0;i < n;i++) {
		int pos;
		cin >> pos;
		if(pos > b && pos < c) {
			max++;
		}
	}
	cout << max << endl;
}