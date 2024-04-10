#include <iostream>
using namespace std;


int a[30];
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		int x = a[i] / 2, y = a[i] - a[i] / 2;
		ans += x * (x - 1) / 2;
		ans += y * (y - 1) / 2;
	}
	cout << ans;
	return 0;
}