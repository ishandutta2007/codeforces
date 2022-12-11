#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

double ans = 0;
bool pm[maxn];
int nd[maxn];
vector<int> rb[maxn];
vector<pair<int, pair<int, int> > > rrb;
ll cnt[maxn];

void dfs(int u) {
	pm[u] = 1;
	nd[u] = 1;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		if(!pm[rb[u][i]]) {
			dfs(rb[u][i]);
			nd[u] += nd[rb[u][i]];
		}
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	ll n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		rrb.pb(mp(c, mp(u, v)));
		rb[u].pb(v);
		rb[v].pb(u);
	}
	dfs(0);
	double del = n * (n - 1) * (n - 2) / 6ll;
	for(int i = 0; i < n - 1; i++) {
		ll tl = min(nd[rrb[i].sc.fs], nd[rrb[i].sc.sc]), tr = n - tl;
		cnt[i] = tl * tr * (tr - 1) + tl * (tl - 1) * tr;
	}
	for(int i = 0; i < n - 1; i++) {
		ans += cnt[i] * rrb[i].fs;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		ll nm, nsz;
		cin >> nm >> nsz; nm--;
		ans += (nsz - rrb[nm].fs) * cnt[nm];
		rrb[nm].fs = nsz;
		cout.precision(12);
		cout << (ans / del) << endl;
	}

	return(0);
}

// by Kim Andrey