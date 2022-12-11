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
const int maxn = 100100;

int dp[100][1 << 20];

int solution() {

	int n;
	scanf("%d\n", &n);
	string s;
	getline(cin, s);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		dp[i - 1][0] = 1;
		int m = 0;
		for (int j = i - 1, l = 0; j >= 0; j--, l++) {
			if (s[j] - '0' > 0 && l > 10) {
				break;
			}
			m |= ((s[j] - '0') << l);
			if (m > 20 || m == 0)
				continue;
			for (int k = 0; k < (1 << 20); k++) {
				dp[i][k | (1 << (m - 1))] += dp[j][k];
				dp[i][k | (1 << (m - 1))] %= mod;
			}
		}
		for (int k = 0, l = 1; k < 20; k++, l |= (l << 1)) {
			cnt += dp[i][l];
			cnt %= mod;
		}
	}
	printf("%d", cnt);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim