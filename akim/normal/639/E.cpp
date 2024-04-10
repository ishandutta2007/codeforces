#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

int n, p[maxn], t[maxn], id1[maxn], id2[maxn];
long double valmin[maxn], valmax[maxn];
ll T = 0;

struct cmp1 {
	bool operator()(const int &a, const int &b) {
		return(p[a] * 1ll * t[b] > p[b] * 1ll * t[a]);
	}
};

struct cmp2 {
	bool operator()(const int &a, const int &b) {
		return(p[a] > p[b]);
	}
};

bool check(long double m) {
	ll pref = 0;
	for(int i = 0, k = 0; i < n;) {
		ll all = 0;
		while(k < n && !cmp1()(id1[i], id1[k]) && !cmp1()(id1[k], id1[i])) {
			all += t[id1[k++]];
		}
		for(; i < k; i++) {
			int j = id1[i];
			valmin[j] = p[j] * (1 - m * ((pref + all) * 1.) / (T * 1.));
			valmax[j] = p[j] * (1 - m * ((pref + t[j]) * 1.) / (T * 1.));
		}
		pref += all;
	}

	bool ok = 1;
	long double mn = mod * 1. * mod;
	for(int i = 1, k = 0; i < n; i++) {
		int j = id2[i];
		while(k < i && p[id2[k]] > p[j]) {
			mn = min(mn, valmin[id2[k]]);
			k++;
		}
		if(valmax[j] > mn) {
			ok = 0;
		}
	}
	return(ok);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	T = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		T += t[i];
	}
	for(int i = 0; i < n; i++) {
		id1[i] = i;
		id2[i] = i;
	}

	sort(&id1[0], &id1[n], cmp1());
	sort(&id2[0], &id2[n], cmp2());

	long double l = 0., r = 1.;
	for(int i = 0; i < 200; i++) {
		long double m = (l + r) / 2.;
		if(check(m)) {
			l = m;
		} else {
			r = m;
		}
	}

	printf("%.10lf", (double)l);

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim