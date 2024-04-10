//MIPT Cryptozoology
//Room 202
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define itn int

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef YA
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

//#define int li

struct Guy {
	int a, b;
	int id;
	bool operator < (const Guy& ot) const {
		return b > ot.b;
	}
};

void solve() {
	int n, p, s;
	cin >> n >> p >> s;
	vector<Guy> guys(n);
	for (int i = 0; i < n; ++i) {
		cin >> guys[i].a;
		guys[i].id = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> guys[i].b;
	}
	sort(all(guys));

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1e9));
	vector<vector<int>> pred(n + 1, vector<int>(n + 1, -1));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int sport = 0; sport <= i; ++sport) {
			if (dp[i + 1][sport + 1] < dp[i][sport] + guys[i].b) {
				dp[i + 1][sport + 1] = dp[i][sport] + guys[i].b;
				pred[i + 1][sport + 1] = 1;
			}
			if (dp[i + 1][sport] < dp[i][sport] + guys[i].a) {
				dp[i + 1][sport] = dp[i][sport] + guys[i].a;
				pred[i + 1][sport] = 0;
			}
		}
	}

	vector<Guy> progrs;
	int res = 0;
	int best_pref = -1;
	for (int i = n - 1; i >= s + p; --i) {
		progrs.push_back(guys[i]);
	}
	sort(all(progrs), [&](const Guy& q, const Guy& w) {
		return q.a > w.a;
	});
	for (int pref = s + p; pref >= s; --pref) {
		int rest = p - pref + s;
		int sum = 0;
		for (int i = 0; i < rest; ++i) {
			sum += progrs[i].a;
		}
		//cout << pref << ' ' << dp[pref][s] << ' ' << sum << "\n";
		if (dp[pref][s] + sum > res) {
			res = dp[pref][s] + sum;
			best_pref = pref;
		}
		progrs.push_back(guys[pref - 1]);
		for (int j = progrs.size() - 1; j > 0; --j) {
			if (progrs[j].a > progrs[j - 1].a) {
				swap(progrs[j].a, progrs[j - 1].a);
			}
		}
	}

	cout << res << "\n";
	vector<vector<int>> ans(2);
	int cur = best_pref;
	int sps = s;
	while (cur > 0) {
		int who = pred[cur][sps];
		ans[who].push_back(guys[cur - 1].id);
		if (who == 1) {
			--sps;
		}
		--cur;
	}
	progrs.clear();
	for (int i = best_pref; i < n; ++i) {
		progrs.push_back(guys[i]);
	}
	sort(all(progrs), [&](const Guy& q, const Guy& w) {
		return q.a > w.a;
	});
	int rest = p - best_pref + s;
	for (int i = 0; i < rest; ++i) {
		ans[0].push_back(progrs[i].id);
	}

	for (int i = 0; i < 2; ++i) {
		for (int c : ans[i]) {
			cout << c + 1 << " ";
		}
		cout << "\n";
	}

}