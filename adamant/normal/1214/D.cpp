#include <bits/stdc++.h>

using namespace std;

const int sz = 7;
int mod[sz];

struct hash_t {
    int r[sz];
	hash_t(){fill(r, r + sz, 0);}
	hash_t(int x){fill(r, r + sz, x);}
	hash_t(const hash_t &t){memcpy(r, t.r, sizeof(r));}
	hash_t operator += (const hash_t &t) {
		for(int i = 0; i < sz; i++) {
			r[i] += t.r[i];
			while(r[i] >= mod[i]) {
				r[i] -= mod[i];
			}
		}
		return *this;
	}
	
	hash_t operator + (const hash_t &t) const {
		return hash_t(*this) += t;
	}
	
	hash_t operator *= (const hash_t &t) {
		for(int i = 0; i < sz; i++) {
			r[i] = 1LL * r[i] * t.r[i] % mod[i];
		}
		return *this;
	}
	
	hash_t operator * (const hash_t &t) const {
		return hash_t(*this) *= t;
	}
	
	bool operator == (const hash_t &t) const {
		return !memcmp(r, t.r, sizeof(r));
	}
};

void init() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < sz; i++) {
		mod[i] = 1 + rng() % 1000000009;
	}
};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int n, m;
	n = 1; m = 1000000;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i < n; i++) {
		s[i] = string(m, '.');
		cin >> s[i];
	}
	hash_t d[2][n + 2][m + 2];
	d[0][1][1] = 1;
	d[1][n][m] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i != 1 || j != 1) {
				d[0][i][j] = (s[i - 1][j - 1] == '.') ? (d[0][i - 1][j] + d[0][i][j - 1]) : 0;
				d[1][n - i + 1][m - j + 1] = (s[n - i][m - j] == '.') ? (d[1][n - i + 1][m - j + 2] + d[1][n - i + 2][m - j + 1]) : 0;
			}
		}
	}
	int ans = 2;
	if(d[0][n][m] == 0) {
		ans = 0;
	} else {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if((i == 1 && j == 1) || (i == n && j == m)) {
					continue;
				}
				if(d[0][n][m] == d[0][i][j] * d[1][i][j]) {
					ans = 1;
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}