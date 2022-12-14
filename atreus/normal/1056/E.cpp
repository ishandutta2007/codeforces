#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;
int base = 37;
ll hsh[maxn], pw[maxn];
string s, t;

ll get (ll fi, ll se) {
	ll ret = hsh[se];
	if (fi == 0)
		return ret;
	return (hsh[se] - hsh[fi - 1] * pw[se - fi + 1] % mod + mod) % mod;
}

bool check (int x, int y) {
	if (y == 0)
		return 0;
	ll fi = -1, se = -1;
	int tmp = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			if (fi != -1 and fi != get (tmp, tmp + x - 1))
				return 0;
			fi = get (tmp, tmp + x - 1);
			tmp += x;
		}
		else {
			if (se != -1 and se != get (tmp, tmp + y - 1))
				return 0;
			se = get (tmp, tmp + y - 1);
			tmp += y;
		}
	}
	if (fi == se)
		return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n = 1000 * 1000 + 10;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * base % mod;
	cin >> s >> t;
	for (int i = 0; i < t.size(); i++)
		hsh[i] = (hsh[i - 1] * base % mod + (t[i] - 'a' + 1)) % mod;

	int x = 0, y = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			x ++;
		}
		else {
			y ++;
		}
	}
	if (x < y) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				s[i] = '0';
			}
			else {
				s[i] = '1';
			}
		}
		swap (x, y);
	}
	ll cnt = 0;
	n = t.size();
	for (int i = 1; i <= t.size() / x; i++) {
		if ((n - i * x) % y == 0 and check (i, (n - i * x) / y)) {
			cnt ++;
		}
	}
	cout << cnt << endl;
}