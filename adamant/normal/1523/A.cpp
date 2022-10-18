#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;
const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2)  : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

void solve() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		bool change = false;
		string st;
		for(size_t i = 0; i < s.size(); i++) {
			int cnt = (i == 0 ? 0 : s[i - 1] == '1') + (i + 1 == s.size() ? 0 : s[i + 1] == '1');
			if(cnt == 1 || s[i] == '1') {
				st += "1";
			} else {
				st += "0";
			}
			change |= st[i] != s[i];
		}
		s = st;
		if(!change) {
			break;
		}
	}
	cout << s << "\n";
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}