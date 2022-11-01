#include <iostream>
using namespace std;

int main() {
	int n, x = 0, ans = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x')
			x++;
		else
			x = 0;
		if (x >= 3)
			ans++;
	}
	cout << ans << endl;
	return 0;
}