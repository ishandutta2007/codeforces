#include <iostream>
using namespace std;

int main() {
	int n, s, sm = 0, maxi = 0;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;;
		maxi = max(maxi, x);
		sm += x;
	}
	if (sm - maxi <= s) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}