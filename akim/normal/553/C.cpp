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

vector<pair<int, int> > rb[maxn];
int col[maxn];
bool pm[maxn];
bool ok = 1;

ll binpow(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) {
			ret = ret * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return(ret);
}

void dfs(int u, int cl) {
	pm[u] = 1;
	col[u] = cl;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		if(!pm[rb[u][i].fs]) {
			if(rb[u][i].sc) {
				dfs(rb[u][i].fs, cl);
			} else {
				dfs(rb[u][i].fs, cl ^ 1);
			}
		} else {
			if(rb[u][i].sc) {
				if(col[rb[u][i].fs] != cl) {
					ok = 0;
				}
			} else {
				if(col[rb[u][i].fs] != 1 - cl) {
					ok = 0;
				}
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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		rb[u].pb(mp(v, c));
		rb[v].pb(mp(u, c));
	}
	int cnt = -1;
	for(int i = 0; i < n; i++) {
		if(!pm[i]) {
			dfs(i, 0);
			cnt++;
		}
	}
	if(!ok) {
		printf("%d", 0);
		return(0);
	} else {
		printf("%I64d", binpow(2, cnt));
	}

	return(0);
}

// by Kim Andrey