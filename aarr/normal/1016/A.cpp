#include <iostream>
using namespace std;



int main() {
	int n, m, s = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s += x;
		cout << s / m << " ";
		s %= m;
	}
	
	return 0;
}