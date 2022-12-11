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
const int maxn = 400100;

char buff[maxn];
int c[maxn];

string ansl[maxn], ansm[maxn];

int solution() {

	int n;
	scanf("%d", &n);
	scanf("%s", buff);
	for(int i = 0; i < n; i++) {
		c[buff[i]]++;
	}
	for(int i = n; i >= 1; i--) {
		if(n % i != 0) continue;
		int cc[500] = {};
		int count = n / i;
		int needd = n - count;
		int needs = count;
		if(!(i & 1)) needs -= count, needd += count;
		for(int j = 0; j < 256; j++) {
			int mx = min(needd, c[j] - cc[j]);
			if(mx & 1) mx--;
			needd -= mx;
			cc[j] += mx;
		}
		for(int j = 0; j < 256; j++) {
			int mx = min(needs, c[j] - cc[j]);
			needs -= mx;
			cc[j] += mx;
		}
		if(needd == 0 && needs == 0) {
			printf("%d\n", count);
			int cc[500] = {};
			int count = n / i;
			int needd = n - count;
			int needs = count;
			if(!(i & 1)) needs -= count, needd += count;
			int cur = 0;
			for(int j = 0; j < 256; j++) {
				int mx = min(needd, c[j] - cc[j]);
				if(mx & 1) mx--;
				needd -= mx;
				cc[j] += mx;
				while(mx) {
					mx -= 2;
					ansl[cur++].pb(char(j));
					cur %= count;
				}
			}
			for(int j = 0; j < 256; j++) {
				int mx = min(needs, c[j] - cc[j]);
				needs -= mx;
				cc[j] += mx;
				while(mx) {
					mx--;
					ansm[cur++].pb(char(j));
					cur %= count;
				}
			}
			for(int i = 0; i < count; i++) {
				printf("%s",ansl[i].c_str());
				printf("%s",ansm[i].c_str());
				reverse(ansl[i].begin(), ansl[i].end());
				printf("%s",ansl[i].c_str());
				if(i != count - 1) printf(" "); else printf("\n");
			}
			return 0;
		}
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim