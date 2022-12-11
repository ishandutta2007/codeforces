#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	if(c == 0) {
		cout << (a==b?"YES":"NO") << endl;
		return 0;
	}
	
	if(abs(b - a) % abs(c) != 0) {
		cout << "NO" << endl;
		return 0;
	}
	
	if((b - a) / c < 0) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	return 0;
}