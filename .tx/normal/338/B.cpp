#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(n) for (int i = 0; i < n; ++i)
#define foj(n) for (int j = 0; j < n; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

// File names!!!

const int MAXN = 1e5;
const int inf = 1e9;

int d;
vector<bool> isbad;
vei maxd;
vei max2d;
vei gr[MAXN];

int calcMaxD(int v, int p) {
	maxd[v] = isbad[v] ? 0 : -inf;
	max2d[v] = maxd[v];
	for (auto i : gr[v]) {
		if (i != p) {
			int cd = calcMaxD(i, v) + 1;
			if (cd >= maxd[v]) {
				max2d[v] = maxd[v];
				maxd[v] = cd;
			} else if (cd > max2d[v]) {
				max2d[v] = cd;
			}
		}
	}
	return maxd[v];
}

int ans = 0;
void calcAns(int v, int pd, int p) {
	// fprintf(stderr, "%d %d %d\n", v, pd, p);
	int w = max(maxd[v], pd);
	// cerr << w << endl;
	if (w <= d) ans++;
	for (auto i : gr[v]) {
		if (i != p) {
			if (maxd[i] + 1 == w) {
				calcAns(i, max(max2d[v] + 1, pd + 1), v);
			} else {
				calcAns(i, w + 1, v);
			}
		}
	}
}

int main() {
	// openfiles("test");
	int n, m;
	scii(n, m);
	sci(d);
	isbad.assign(n, false);
	foi(m) {
		int x;
		sci(x);
		isbad[x - 1] = true;
	}
	foi(n - 1) {
		int x, y;
		scii(x, y);
		--x; --y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	maxd.resize(n);
	max2d.resize(n);

	calcMaxD(0, -1);

	// for (auto i : max2d) {
	// 	cerr << i << " ";
	// }
	// cerr << endl;
	
	calcAns(0, -inf, -1);

	pri(ans);

	puts("");
    return 0;
}//ldasiv