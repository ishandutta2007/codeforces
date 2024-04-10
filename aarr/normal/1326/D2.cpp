#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod1 = 1000 * 1000 * 1000 + 7, mod2 = 1000 * 1000 * 1000 + 123, D = 29, N = 1000 * 1000 + 7;
string s;
long long po1[N], po2[N];
long long fl1[N], fl2[N], fr1[N], fr2[N];


bool pal2(int l, int r) {
	for (int i = l; i < r; i++) {
		if (s[i] != s[r - i + l - 1]) {
			return false;
		}
	}
	return true;
}
bool pal(int l, int r) {
	long long hl1 = fl1[r - 1], hl2 = fl2[r - 1], hr1 = fr1[l], hr2 = fr2[l];
	hr1 -= 1ll * fr1[r] * po1[r - l] - 1ll * mod1 * mod1, hr2 -= 1ll * fr2[r] * po2[r - l] - 1ll * mod2 * mod2;
	if (l > 0) {
		hl1 -= 1ll * fl1[l - 1] * po1[r - l] - 1ll * mod1 * mod1, hl2 -= 1ll * fl2[l - 1] * po2[r - l] - 1ll * mod2 * mod2;
	}
	hl1 %= mod1, hl2 %= mod2, hr1 %= mod1, hr2 %= mod2;
//	hl1 *= po1[s.size() - r - 1], hl2 *= po2[s.size() - r - 1];
//	hr1 *= po2[l], hr2 *= po2[l];
//	hl1 %= mod1, hl2 %= mod2, hr1 %= mod1, hr2 %= mod2;
	if (hl1 == hr1 && hl2 == hr2) {
		return true;
	}
	return false;
}
int32_t main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	po1[0] = po2[0] = 1;
	for (int i = 1; i < N; i++) {
		po1[i] = po1[i - 1] * D;
		po2[i] = po2[i - 1] * D;
		po1[i] %= mod1;
		po2[i] %= mod2;
	}
	for (int ii = 0; ii < t; ii++) {
		cin >> s;
		if (pal2(0, s.size())) {
			cout << s << '\n';
			continue;
		}
		fr1[s.size()] = fr2[s.size()] = fl1[s.size()] = fl2[s.size()] = 0;
		for (int i = 0; i < s.size(); i++) {
			fl1[i] = fl2[i] = 0;
			if (i > 0) {
				fl1[i] = fl1[i - 1] * D;
				fl2[i] = fl2[i - 1] * D;
			}
			fl1[i] += s[i] - 'a' + 1;
			fl2[i] += s[i] - 'a' + 1;
			fl1[i] %= mod1;
			fl2[i] %= mod2;
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			fr1[i] = fr2[i] = 0;
			if (i < s.size()) {
				fr1[i] = fr1[i + 1] * D;
				fr2[i] = fr2[i + 1] * D;
			}
			fr1[i] += s[i] - 'a' + 1;
			fr2[i] += s[i] - 'a' + 1;
			fr1[i] %= mod1;
			fr2[i] %= mod2;
		}
		int lt = s.size() / 2;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - i - 1]) {
				lt = i;
				break;
			} 
		}
		int l = lt - 1, r = s.size() - lt;
		int x = -1, y = s.size() + 1;
		for (int i = l + 1; i < r; i++) {
			if (pal(l + 1, i + 1)) {
				x = i;
			}
		}
		for (int i = r - 1; i > l; i--) {
			if (pal(i, r)) {
				y = i;
			}
		}
	//	cout << l << " " << r << " " << x << " " << y << endl;
		if (x - l >= r - y) {
			for (int i = 0; i <= x; i++) {
				cout << s[i];
			}
			for (int i = r; i < s.size(); i++) {
				cout << s[i];
			}
		}
		else {
			for (int i = 0; i <= l; i++) {
				cout << s[i];
			}
			for (int i = y; i < s.size(); i++) {
				cout << s[i];
			}
		}
		cout << '\n';
	}
	return 0;
}