#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>

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
const int maxn = 200100;

int lb[30], lf[maxn], rg[maxn], lmx[maxn], rmx[maxn];
int a[maxn];

int solution() {

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		lf[i] = -1;
		rg[i] = n;
	}

	vector<int> vc;

	vc.clear();
	memset(lb, -1, sizeof lb);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 30; j++)
			if(!(a[i] & (1 << j)))
				lf[i] = max(lf[i], lb[j] == -1 ? -1 : lb[j]);
		for(int j = 0; j < 30; j++)
			if(a[i] & (1 << j))
				lb[j] = i;
		while(!vc.empty() && a[vc.back()] <= a[i])
			vc.ppb();
		if(!vc.empty()) {
			lmx[i] = vc.back();
		} else {
			lmx[i] = -1;
		}
		lf[i] = max(lf[i], lmx[i]);
		vc.pb(i);
	}

	vc.clear();
	memset(lb, -1, sizeof lb);
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < 30; j++)
			if(!(a[i] & (1 << j)))
				rg[i] = min(rg[i], lb[j] == -1 ? n : lb[j]);
		for(int j = 0; j < 30; j++)
			if(a[i] & (1 << j))
				lb[j] = i;
		while(!vc.empty() && a[vc.back()] < a[i])
			vc.ppb();
		if(!vc.empty()) {
			rmx[i] = vc.back();
		} else {
			rmx[i] = n;
		}
		rg[i] = min(rg[i], rmx[i]);
		vc.pb(i);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
//		cout << lmx[i] << " " << rmx[i] << " " << lf[i] << " " << rg[i] << endl;
		ans += (lf[i] - lmx[i]) * 1ll * (rmx[i] - i) + (rmx[i] - rg[i]) * 1ll * (i - lmx[i]) - (lf[i] - lmx[i]) * 1ll * (rmx[i] - rg[i]);
	}

	printf("%lld", ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim