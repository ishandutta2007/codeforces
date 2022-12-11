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

set<pair<int, int> > added;
vector<int> rb[maxn];
vector<pair<int, int> > bad, good;
bool pm[maxn];

void dfs(int u, int p = -1) {
	pm[u] = 1;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		if(!pm[rb[u][i]]) {
			dfs(rb[u][i], u);
		} else
		if(rb[u][i] != p) {
			if(!added.count(mp(u, rb[u][i]))) {
				bad.pb(mp(rb[u][i], u));
				added.insert(mp(rb[u][i], u));
			}
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
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		rb[u].pb(v);
		rb[v].pb(u);
	}

	for(int i = 1; i <= n; i++) {
		if(!pm[i]) {
			dfs(i);
			if(i == 1) continue;
			good.pb(mp(1, i));
		}
	}
//	{
//		cout << bad.size() << " " << good.size() << endl;
//		for(int i = 0; i < (int)bad.size(); i++) {
//			printf("%d %d\n", bad[i].fs, bad[i].sc);
//		}
//	}
//	assert(bad.size() == good.size());
	printf("%d\n", (int)bad.size());
	for(int i = 0; i < (int)bad.size(); i++) {
		printf("%d %d %d %d\n", bad[i].fs, bad[i].sc, good[i].fs, good[i].sc);
	}

	return(0);
}

// by Kim Andrey