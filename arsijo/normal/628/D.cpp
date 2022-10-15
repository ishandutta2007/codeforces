#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
//#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ll solve(string s, int m, int d, int t = 0) {
	int n = (int) s.size();
	ll dp[n][m];
	ms(dp);
	int v = s[0] - '0';
	for (int i = 1; i < v; i++) {
		if (d == i)
			continue;
		dp[0][i % m]++;
	}
	int w = (s[0] - '0') % m;
	bool ok = s[0] - '0' != d;
	for (int i = 1; i < n; i++) {
		bool r = i % 2;
		if (r) {
			if (ok && s[i] - '0' > d) {
				dbg
					cout << "inc " << i << " " << (w * 10 + d) << endl;
				dp[i][(w * 10 + d) % m]++;
			}
			for (int z = 0; z < m; z++)
				dp[i][(z * 10 + d) % m] += dp[i - 1][z];
			if (s[i] - '0' != d)
				ok = false;
		} else {
			for (int j = 0; j < 10; j++) {
				if (j == d)
					continue;
				for (int z = 0; z < m; z++) {
					dp[i][(z * 10 + j) % m] += dp[i - 1][z];
				}
			}
			if (ok) {
				for (int j = 0; j < s[i] - '0'; j++) {
					if (j == d)
						continue;
					dbg
						cout << "+ " << (w * 10 + j) % m << endl;
					dp[i][(w * 10 + j) % m]++;
				}
				if (s[i] - '0' == d)
					ok = false;
			}
		}
		for (int z = 0; z < m; z++)
			dp[i][z] = dp[i][z]mod;
		w = (w * 10 + (s[i] - '0')) % m;
		dbg
			cout << w << endl;
	}
	dbg
		cout << s << endl;
	dbg
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	if (ok && w == 0) {
		dp[n - 1][0] = (dp[n - 1][0] + 1)mod;
	}
	dbg
		cout << ok << endl;
	dbg
		cout << "res for " << s << " = " << dp[n - 1][0] << endl;
	return dp[n - 1][0];
}

void dec(string &s) {
	for (int i = (int) s.size() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			s[i] = '9';
		} else {
			s[i]--;
			break;
		}
	}
	if (s[0] == '0') {
		s.erase(s.begin());
	}
}

void inc(string &s) {
	for (int i = (int) s.size() - 1; i >= 0; i--) {
		if (s[i] == '9') {
			s[i] = '0';
		} else {
			s[i]++;
			break;
		}
	}
}

int get_mod(string s, int m) {
	int ans = 0;
	for (int i = 0; i < (int) s.size(); i++)
		ans = (ans * 10 + s[i] - '0') % m;
	return ans;
}

bool check(string s, int q) {
	for (int i = 1; i < (int) s.size(); i += 2)
		if (s[i] - '0' != q)
			return false;
	for (int i = 0; i < (int) s.size(); i += 2)
		if (s[i] - '0' == q)
			return false;
	return true;
}

ll solve_long(string s1, string s2, int m, int d, bool bol = true) {
	int ans = 0;
	while (s1 != s2) {
		if (get_mod(s1, m) == 0 && check(s1, d)) {
			dbg
				if (bol)
					cout << s1 << endl;
			ans++;
		}
		inc(s1);
	}
	if (get_mod(s1, m) == 0 && check(s1, d)) {
		ans++;
		dbg
			if (bol)
				cout << s1 << endl;
	}
	return ans;
}

bool _less(string s1, string s2) {
	for (int i = 0; i < (int) s1.size(); i++)
		if (s1[i] != s2[i])
			return s1[i] < s2[i];
	return false;
}

string get_rand(int n) {
	string ans;
	ans += char(rand() % 9 + '1');
	for (int i = 1; i < n; i++)
		ans += char(rand() % 10 + '0');
	return ans;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	string s1, s2;
	cin >> s1 >> s2;
#ifdef LOCAL
	{
		cout << "ans = " << solve_long(s1, s2, n, m) << endl;
		if(1) {
			string q = "1" + string((int) s1.size() - 1, '0');
			dec(s1);
			cout << solve_long(q, s1, n, m, false) << " " << solve_long(q, s2, n, m, false) << endl;
			inc(s1);
		}
	}
#endif
	if(s1 == "0") {
		cout << solve(s2, n, m);
	} else {
		dec(s1);
		if(s1.size() != s2.size()) {
			cout << solve(s2, n, m) << endl;
		} else {
			cout << (solve(s2, n, m) + MOD - solve(s1, n, m)) mod;
		}
	}

}