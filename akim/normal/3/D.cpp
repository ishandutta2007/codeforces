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
const int maxn = 100100;

int a[maxn], pr[maxn];
int sz = 0;
int izm[4 * maxn], mi[4 * maxn];
int bal[maxn];
int idx[maxn];

bool cmp(int a, int b) {
	return(pr[a] < pr[b]);
}

void build(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < lf || rg < tl) {
		return;
	}
	if(tl == tr) {
		mi[v] = bal[tl];
		mi[v] -= izm[v];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(lf, rg, v * 2 + 1, tl, tm);
	build(lf, rg, v * 2 + 2, tm + 1, tr);
	mi[v] = min(mi[v * 2 + 1], mi[v * 2 + 2]);
	mi[v] -= izm[v];
}

void dec(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < lf || rg < tl) {
		return;
	}
	if(tl >= lf && tr <= rg) {
		izm[v] += 2;
		mi[v] -= 2;
		return;
	}
	int tm = (tl + tr) >> 1;
	dec(lf, rg, v * 2 + 1, tl, tm);
	dec(lf, rg, v * 2 + 2, tm + 1, tr);
	mi[v] = min(mi[v * 2 + 1], mi[v * 2 + 2]);
	mi[v] -= izm[v];
}

int getmin(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < lf || rg < tl) {
		return(mod);
	}
	if(tl >= lf && tr <= rg) {
		return(mi[v]);
	}
	int tm = (tl + tr) >> 1;
	int ans = min(getmin(lf, rg, v * 2 + 1, tl, tm),
	getmin(lf, rg, v * 2 + 2, tm + 1, tr));
	return(ans - izm[v]);
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

	ll price = 0;
	string s;
	getline(cin, s);
	int n = s.length();
	for(int i = 0; i < n; i++) {
		if(s[i] == '?') {
			s[i] = '(';
			a[sz++] = i;
		}
		if(s[i] == '(') {
			bal[i] = i - 1 >= 0 ? bal[i - 1] + 1 : 1;
		} else {
			bal[i] = i - 1 >= 0 ? bal[i - 1] - 1 : -1;
		}
		if(bal[i] < 0) {
			printf("-1");
			return(0);
		}
	}

	for(int i = 0; i < sz; i++) {
		idx[i] = i;
		int op, cl;
		scanf("%d%d", &op, &cl);
		price += op;
		pr[i] = cl - op;
	}

	sort(&idx[0], &idx[sz], cmp);
	build(0, n - 1);
	for(int i = 0; i < sz; i++) {
		if(getmin(a[idx[i]], n - 1) <= 1) {
			continue;
		}
		price += pr[idx[i]];
		s[a[idx[i]]] = ')';
		dec(a[idx[i]], n - 1);
	}

//	cerr << s << endl;

	if(getmin(n - 1, n - 1) == 0) {
		printf("%lld\n%s", price, s.c_str());
	} else {
		printf("-1");
	}

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