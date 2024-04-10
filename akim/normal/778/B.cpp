#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//																														tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

void initialization() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(__rdtsc());
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	finish(solution());
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1010;

bool pd[5 * maxn][maxn][2];
int dp[maxn][2];
map<string, int> ma;
int em = 0;

int solution() {

	ma["?"] = -1;

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int id = ma.count(s) ? ma[s] : ma[s] = em++;
		cin >> s;
		cin >> s;
		if (isdigit(s[0])) {
			for (int j = 0; j < m; j++) {
				if (s[j] == '0') {
					pd[i][j][0] = 0;
					pd[i][j][1] = 0;
				} else {
					pd[i][j][0] = 1;
					pd[i][j][1] = 1;
				}
			}
		} else {
			int lid = ma.count(s) ? ma[s] : ma[s] = em++;
			string op;
			cin >> op >> s;
			int rid = ma.count(s) ? ma[s] : ma[s] = em++;
			if (lid > rid)
				swap(lid, rid);
			if (op == "XOR") {
				if (lid == -1 && rid == -1) {
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = 0;
						pd[i][j][1] = 0;
					}
				} else if (lid == -1) {
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = pd[rid][j][0] ^ 0;
						pd[i][j][1] = pd[rid][j][1] ^ 1;
					}
				} else
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = pd[lid][j][0] ^ pd[rid][j][0];
						pd[i][j][1] = pd[lid][j][1] ^ pd[rid][j][1];
					}
			}
			if (op == "AND") {
				if (lid == -1 && rid == -1) {
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = 0;
						pd[i][j][1] = 1;
					}
				} else if (lid == -1) {
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = pd[rid][j][0] & 0;
						pd[i][j][1] = pd[rid][j][1] & 1;
					}
				} else
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = pd[lid][j][0] & pd[rid][j][0];
						pd[i][j][1] = pd[lid][j][1] & pd[rid][j][1];
					}
			}
			if (op == "OR") {
				if (lid == -1 && rid == -1) {
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = 0;
						pd[i][j][1] = 1;
					}
				} else if (lid == -1) {
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = pd[rid][j][0] | 0;
						pd[i][j][1] = pd[rid][j][1] | 1;
					}
				} else
					for (int j = 0; j < m; j++) {
						pd[i][j][0] = pd[lid][j][0] | pd[rid][j][0];
						pd[i][j][1] = pd[lid][j][1] | pd[rid][j][1];
					}
			}
		}
		for (int j = 0; j < m; j++) {
			dp[j][0] += pd[i][j][0];
			dp[j][1] += pd[i][j][1];
		}
	}
	for (int i = 0; i < m; i++) {
		if (dp[i][0] > dp[i][1]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		if (dp[i][0] < dp[i][1]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << endl;

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim