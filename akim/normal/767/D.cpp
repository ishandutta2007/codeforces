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
const int maxn = 10010000;

int s[maxn];
pair<int, int> a[2002000];

void add(int u) {
	for (; u < maxn; u |= u + 1) {
		s[u]++;
	}
}
int get(int u) {
	int ret = 0;
	for (; u >= 0; u &= u + 1, u--) {
		ret += s[u];
	}
	return (ret);
}

int solution() {

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].fs);
		a[i].sc = -i - 1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[n + i].fs);
		a[n + i].sc = i + 1;
	}
	sort(&a[0], &a[n + m]);
	vector<int> vc;
	for (int i = 0; i < n + m; i++) {
		if (get(a[i].fs) < k * 1ll * (a[i].fs + 1)) {
			add(a[i].fs);
			if (a[i].sc > 0) {
				vc.pb(a[i].sc);
			}
		} else {
			if (a[i].sc < 0) {
				if (vc.empty()) {
					printf("-1");
					return (0);
				} else {
					vc.ppb();
				}
			}
		}
	}
	printf("%d\n", (int) vc.size());
	for (int i : vc) {
		printf("%d ", i);
	}


	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim