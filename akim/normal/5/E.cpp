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
const int maxn = 3000100;

int a[maxn];
int lf[maxn], rg[maxn], cnt[maxn];

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

	int n, mx = 0, pos, cont = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i + n + n] = a[i + n] = a[i];
		if(mx < a[i]) {
			pos = i;
			mx = a[i];
			cont = 1;
		} else
		if(mx == a[i]) {
			cont++;
		}
	}
	pos += n;
	cnt[0] = 0;
	for(int i = pos + n - 1; i >= pos + 0; i--) {
		rg[i] = i + 1;
		while(rg[i] <= pos + n - 1 && a[i] > a[rg[i]]) rg[i] = rg[rg[i]];
		if(rg[i] <= pos + n - 1 && a[i] == a[rg[i]]) {
			cnt[i] = cnt[rg[i]] + 1;
			rg[i] = rg[rg[i]];
		}
	}
	lf[pos] = pos;
	for(int i = pos + 0; i <= pos + n - 1; i++) {
		lf[i] = i - 1;
		while(lf[i] >= pos + 0 && a[i] > a[lf[i]]) lf[i] = lf[lf[i]];
		if(lf[i] >= pos + 0 && a[i] == a[lf[i]]) {
			lf[i] = lf[lf[i]];
		}
	}
	ll ans = 0;
	for(int i = pos + 0; i < pos + n; i++) {
		ans +=
				(lf[i] == pos - 1 && rg[i] == pos + n ? 0 : 2) +
				cnt[i];
	}

	int asdf = 0;
	if(cont == 1) {
		int mmx = 0, mcont = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] != mx) {
				if(a[i] > mmx) {
					mmx = a[i];
					mcont = 1;
				} else
				if(a[i] == mmx) {
					mcont++;
				}
			}
		}
		asdf = mcont;
	}

	cout << ans - asdf;

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