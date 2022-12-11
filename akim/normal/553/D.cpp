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

struct drb {
	int ch, zn;
};
bool operator <(const drb& x, const drb& y) {
    return((x.ch * 1. / x.zn * 1.) < (y.ch * 1. / y.zn * 1.));
}

multiset<pair<drb, int> > mst;
bool pm[maxn];
vector<int> rb[maxn];
drb val[maxn];

drb vala;
bool ans[maxn];
int cnt = 0;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	vala.ch = -1;
	vala.zn = 1;

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++) {
		int u;
		scanf("%d", &u);
		u--;
		pm[u] = 1;
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	for(int i = 0; i < n; i++) {
		if(pm[i]) continue;
		val[i].ch = 0;
		val[i].zn = rb[i].size();
		for(int f = 0; f < (int)rb[i].size(); f++) {
			if(!pm[rb[i][f]]) {
				val[i].ch++;
			}
		}
		mst.insert(mp(val[i], i));
	}
	while(!mst.empty()) {
		pair<drb, int> p = *mst.begin();

		if(vala < p.fs) {
			vala = p.fs;
			cnt = 0;
			for(int i = 0; i < n; i++) {
				ans[i] = pm[i];
				cnt += !pm[i];
			}
		}
		mst.erase(mst.begin());
		int u = p.sc;
		pm[u] = 1;
		for(int i = 0; i < (int)rb[u].size(); i++) {
			if(!pm[rb[u][i]]) {
				mst.erase(mst.find(mp(val[rb[u][i]], rb[u][i])));
				val[rb[u][i]].ch--;
				mst.insert(mp(val[rb[u][i]], rb[u][i]));
			}
		}
	}

	printf("%d\n", cnt);
	for(int i = 0; i < n; i++) {
		if(!ans[i]) {
			printf("%d ", i + 1);
		}
	}

	return(0);
}

// by Kim Andrey