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
const int maxn = 10 * 100100;

vector<int> rb[maxn];
int st[maxn];
int qu[maxn * 3];
int dp[maxn];
bool used[maxn];

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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		rb[v].pb(u);
		st[u]++;
	}
	for(int i = 0; i <= n; i++) dp[i] = mod;

	int pl = maxn * 3 / 2, pr = maxn * 3 / 2 + 1;
	int u, v;
	scanf("%d%d", &u, &v);
	dp[v] = 0;
	qu[pl] = v;
	while(pl < pr) {
		int pos = qu[pl++];
		if(pos == u) break;
		if(used[pos]) continue;
		used[pos] = 1;
		for(int i = 0; i < (int)rb[pos].size(); i++) {
			if(--st[rb[pos][i]] == 0) {
				if(dp[pos] < dp[rb[pos][i]]) {
					dp[rb[pos][i]] = dp[pos];
					qu[--pl] = rb[pos][i];
				}
			} else {
				if(dp[rb[pos][i]] == mod) {
					dp[rb[pos][i]] = dp[pos] + 1;
					qu[pr++] = rb[pos][i];
				}
			}
		}
	}

	printf("%d", dp[u] == mod ? -1 : dp[u]);

	return(0);
}

// by Kim Andrey