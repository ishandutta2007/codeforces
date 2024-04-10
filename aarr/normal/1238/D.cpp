#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	string s;
	cin >> s;
	long long ans = n * (n - 1) / 2;
	ans -= 2 * n;
	for (int i = 0; i < n && s[i] == s[0]; i++) {
		ans++;
	}
	for (int i = n - 1; i >= 0 && s[i] == s[n - 1]; i--) {
		ans++;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1])
			ans++;
	}
	cout << ans << endl;
	return 0;
}