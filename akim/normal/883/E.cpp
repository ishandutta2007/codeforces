#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map = tree<T1, T2, std::less<T1>, rb_tree_tag, tree_order_statistics_node_update>;

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

#ifdef SOL
double starttime;
#endif

void initialization() {
#ifdef SOL
	starttime = 1000. * clock() / CLOCKS_PER_SEC;
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
	} else
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
	fprintf(stderr, "\n-----------------\nexit value: %d\ntime: %.3lf ms\n-----------------\n", exitval, 1000. * clock() / CLOCKS_PER_SEC - starttime);
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
const int maxn = 100;

bool used[26], gue[26];
char s[maxn];
int c[26];
char ss[1100][maxn];

int solution() {

	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; i < n; i++) {
		if(s[i] != '*') {
			used[s[i] - 'a'] = 1;
		}
	}
	int m, cnt = 0;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%s", ss[i]);
		bool ok = 1;
		for(int j = 0; j < n; j++)
			if(s[j] != '*') {
				if(s[j] != ss[i][j]) {
					ok = 0;
				}
			} else {
				if(used[ss[i][j] - 'a']) {
					ok = 0;
				}
			}
		bool u[26] = {};
		if(ok) {
			for(int j = 0; j < n; j++) {
				c[ss[i][j] - 'a'] += !u[ss[i][j] - 'a'];
				u[ss[i][j] - 'a'] = 1;
			}
			cnt++;
		}
	}
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		if(!used[i] && c[i] == cnt) {
			ans++;
		}
	}
	printf("%d", ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim