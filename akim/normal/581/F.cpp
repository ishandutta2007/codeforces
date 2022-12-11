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
const int mod = (int)5050;
const double pi = acos(-1.);
const int maxn = 5050;

vector<int> rb[maxn];

int dp[maxn][2][maxn];
bool was[maxn][2][maxn];
int st[maxn], cnt = 0, chld[maxn];
bool pm[maxn];
int sz[maxn];

int get(int a, int b, int c) {
	if(was[a][b][c]) {
		return(dp[a][b][c]);
	}
	return(mod);
}

void dfs(int u) {
//	cerr << u + 1 << endl;
	pm[u] = 1;
	chld[u] = 0;
	sz[u] = 0;
	if(st[u] == 1) {
		sz[u] = 1;
		chld[u] = 1;
		was[u][0][0] = 1;
		dp[u][0][0] = 0;
		was[u][1][1] = 1;
		dp[u][1][1] = 0;
	}
	for(int i = 0; i < (int)rb[u].size(); i++) if(!pm[rb[u][i]]) {
		int v = rb[u][i];
		dfs(v);
		sz[u] += chld[v];
		for(int g = sz[u]; g >= 0; g--) {
			was[u][0][g] = 0;
			was[u][1][g] = 0;
			for(int f = 0; f <= min(chld[v], g); f++) {
				if(!was[u][0][g]) {
					int val0 = mod, val1 = mod;
					if(g - f <= chld[u]) {
						was[u][0][g] = 1;
						if(chld[u] != 0) val0 = get(u, 0, g - f) + min(get(v, 0, f), get(v, 1, f) + 1); else
							val0 = min(get(v, 0, f), get(v, 1, f) + 1);
					}
					if(g - f <= chld[u]) {
						was[u][1][g] = 1;
						if(chld[u] != 0) val1 = get(u, 1, g - f) + min(get(v, 0, f) + 1, get(v, 1, f)); else
							val1 = min(get(v, 0, f) + 1, get(v, 1, f));
					}
					dp[u][0][g] = val0;
					dp[u][1][g] = val1;
				} else {
					int val0, val1;
					val0 = min(dp[u][0][g], get(u, 0, g - f) + min(get(v, 0, f), get(v, 1, f) + 1));
					val1 = min(dp[u][1][g], get(u, 1, g - f) + min(get(v, 0, f) + 1, get(v, 1, f)));
					dp[u][0][g] = val0;
					dp[u][1][g] = val1;
				}
			}
		}
		chld[u] += chld[v];
	}
//	cout << u + 1 << endl;
//	for(int i = 0; i <= chld[u]; i++) {
//		printf("%d ", dp[u][0][i]);
//	}printf("\n");
//	for(int i = 0; i <= chld[u]; i++) {
//		printf("%d ", dp[u][1][i]);
//	}printf("\n");
//	printf("-------------\n");
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
	if(n == 2) {
		printf("1");
		return(0);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
		st[u]++, st[v]++;
	}

	int rt;
	for(int i = 0; i < n; i++) {
		if(st[i] > 1) {
			rt = i;
		} else {
			cnt++;
		}
	}
	cnt /= 2;

	dfs(rt);

	printf("%d", min(dp[rt][0][cnt], dp[rt][1][cnt]));

	return(0);
}

// by Kim Andrey