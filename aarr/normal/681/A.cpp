#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool ans = false;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;
		if (x >= 2400 && y > x)
			ans = true;
	}
	if (ans)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}