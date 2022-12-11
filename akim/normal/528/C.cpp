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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int n, m;
vector<pair<int, int> > rb[maxn];
int i[maxn];
vector<int> ans;
bool used[4 * maxn];
int prvodd = -1;

void dfs(int u) {
	for(; i[u] < (int)rb[u].size(); i[u]++) {
		if(!used[rb[u][i[u]].sc]) {
			used[rb[u][i[u]].sc] = 1;
			dfs(rb[u][i[u]].fs);
		}
	}
	ans.pb(u + 1);
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

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		rb[u].pb(mp(v, i));
		rb[v].pb(mp(u, i));
	}

	for(int i = 0; i < n; i++) {
		if(rb[i].size() & 1) {
			if(prvodd == -1) {
				prvodd = i;
			} else {
				rb[prvodd].pb(mp(i, m));
				rb[i].pb(mp(prvodd, m));
				m++;
				prvodd = -1;
			}
		}
	}

	if(m & 1) {
		rb[0].pb(mp(0, m));
		rb[0].pb(mp(0, m));
		m++;
	}

	dfs(0);

	printf("%d\n", m);
	for(int i = 0; i < (int)ans.size() - 1; i++) {
		printf("%d %d\n", ans[i + 1 - (i & 1)], ans[i + (i & 1)]);
	}

	return(0);
}

// by Kim Andrey