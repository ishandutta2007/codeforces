#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, k;
int dp[101][55][10];
int temp[55][10];
int mod  = 1000000007;
vector<int> g[100100];

void add(int &v, int u){
	v += u;
	if(v >= mod) v-=mod;
}
void merge(int a, int b){
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= 1; j++){
			temp[i][j] = dp[a][i][j];
			dp[a][i][j] = 0;
		}
	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= k; j++){
			add(dp[a][min(i, j + 1)][0], temp[i][0] * 1ll * dp[b][j][0] % mod);
			if(i + j + 1 <= k)
				add(dp[a][i][0], temp[i][0] * 1ll * dp[b][j][1] % mod);
			else {
				add(dp[a][j + 1][1], temp[i][0] * 1ll * dp[b][j][1] % mod);
			}
			add(dp[a][max(i, j + 1)][1], temp[i][1] * 1ll * dp[b][j][1] % mod);
			if(i + j + 1 <= k)
				add(dp[a][j + 1][0], temp[i][1] * 1ll * dp[b][j][0] % mod);
			else {
				add(dp[a][i][1], temp[i][1] * 1ll * dp[b][j][0] % mod);
			}
		}
	}
}
void dfs(int v, int pa){
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == pa) continue;
		dfs(to, v);
	}
	dp[v][0][0]++;
	dp[v][0][1]++;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == pa) continue;
		merge(v, to);
	}
}
void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 1, x,y; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	int ans = 0;
	for(int i = 0; i <= k; i++){
		add(ans, dp[1][i][0]);
		
	}
	printf("%d\n", ans);
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}