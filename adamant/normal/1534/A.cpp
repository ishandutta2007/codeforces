#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % mod;
}

int mul(int a,int b) {
	return a * b % mod;
}

int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

int inv(int x) {
	return bpow(x, mod - 2);
}

int sub(int a, int b) {
	return (a + mod - b) % mod;
}

int dv(int a, int b) {
	return mul(a, inv(b));
}

const int maxn = 3e5 + 42;

void solve() {
	int n, m;
	cin >> n >> m;
	
	string s[n];
	int type = 0;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		for(int j = 0; j < m; j++) {
			if(s[i][j] != '.') {
				int t = ((i + j) % 2) xor (s[i][j] == 'R');
				if(type) {
					type = t % 2 == type % 2 ? type : -1;
				} else {
					type = t ? 1 : 2;
				}
			}
		}
	}
	if(type == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for(int i = 0; i < n; i++) {
			string t;
			for(int j = 0; j < m; j++) {
				t += (i + j + type) % 2 ? 'R' : 'W';
			}
			cout << t << "\n";
		}
	}
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}