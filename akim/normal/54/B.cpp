#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

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
const int maxn = 22;

char c[maxn][maxn];

int solution() {

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int j = 0; j < m; j++) {
			scanf("%c", &c[i][j]);
		}
	}

	int ans = 0, S = mod, x, y;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!(n % i == 0 && m % j == 0)) continue;
			set<vector<string> > st;
			bool good = 1;
			for(int ii = 0; ii < n; ii += i) {
				for(int jj = 0; jj < m; jj += j) {
					vector<vector<string> > vvc;
					vector<string> vc;
					string s;
					{
						s.clear();
						for(int iii = 0; iii < i; iii++) {
							for(int jjj = 0; jjj < j; jjj++) {
								s.pb(c[ii + iii][jj + jjj]);
							}
						}
						vc.pb(s);
					}
					{
						s.clear();
						for(int jjj = j - 1; jjj >= 0; jjj--) {
							for(int iii = 0; iii < i; iii++) {
								s.pb(c[ii + iii][jj + jjj]);
							}
						}
						vc.pb(s);
					}
					{
						s.clear();
						for(int iii = i - 1; iii >= 0; iii--) {
							for(int jjj = j - 1; jjj >= 0; jjj--) {
								s.pb(c[ii + iii][jj + jjj]);
							}
						}
						vc.pb(s);
					}
					{
						s.clear();
						for(int jjj = 0; jjj < j; jjj++) {
							for(int iii = i - 1; iii >= 0; iii--) {
								s.pb(c[ii + iii][jj + jjj]);
							}
						}
						vc.pb(s);
					}
					for(int i = 0; i < 4; i++) {
						vvc.pb(vc);
						vc.pb(vc[0]);
						vc.erase(vc.begin());
					}
					sort(vvc.begin(), vvc.end());
					if(st.count(vvc[0])) {
						good = 0;
						break;
					}
					st.insert(vvc[0]);
				}
				if(!good) break;
			}
			if(good) {
				ans++;
				if(i * j < S) {
					S = i * j;
					x = i, y = j;
				} else if(i * j == S && i < x) {
					x = i, y = j;
				}
			}
		}
	}

	printf("%d\n%d %d\n", ans, x, y);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim