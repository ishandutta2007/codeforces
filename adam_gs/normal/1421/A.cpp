#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		a^=b;
		cout << a << '\n';
	}
}