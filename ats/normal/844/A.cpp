#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int k;
	cin >> k;
	int a[26];
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < s.size(); i++) {
		a[(int)(s[i] - 'a')]++;
	}
	
	int t = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] != 0) {
			t++;
		}
		else {
			a[i] = 100000000;
		}
	}
	sort(a, a + 26);
	if (k > s.size()) {
		cout << "impossible" << endl;
	}
	else if (k - t < 0) {
		cout << 0 << endl;
	}
	else {
		cout << k - t << endl;
	}
	
	return 0;
}