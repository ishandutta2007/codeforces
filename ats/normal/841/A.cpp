#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int a[26];
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		a[(int)(s[i] - 'a')]++;
	}
	int t = 0;
	for (int i = 0; i < 26; i++) {
		t = max(t, a[i]);
	}
	if (t > k) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}