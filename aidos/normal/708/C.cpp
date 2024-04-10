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
int dp[400100];
int mx1[400100];
int mx2[400100];
vector<int> g[400100];
int n;
void dfs(int v, int p){
	dp[v] = 1;
	mx1[v] = 0;
	mx2[v] = 0;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		dp[v] += dp[to];
		
		if(dp[to] * 2 > n){
			if(mx1[v] < mx1[to]){
				mx2[v] = mx1[v];
				mx1[v] = mx1[to];
			}
			else if(mx1[to] > mx2[v]){
				mx2[v] = mx1[to];
			}
			continue;
		}
		if(dp[to] > mx1[v]){
			mx2[v] = mx1[v];
			mx1[v] = dp[to];
		}
		else if(dp[to] > mx2[v]){
			mx2[v] = dp[to];
		}
	}
}
int ans[400400];
void calc(int v, int p, int sz, int mx){
	if(sz * 2 > n){
		if((sz - mx) * 2 > n)
			ans[v] = 0;
		else ans[v] = 1;
	}
	else {
		ans[v] = 1;
	}
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		if(dp[to] * 2 > n){
			if((dp[to] - mx1[to]) * 2 > n) ans[v] = 0;
		}
		int mxi = mx;
		int szi = sz + dp[v] - dp[to];
		if(szi * 2 <= n ){
			mxi = szi;
		}
		else {
			if(mx1[v] == dp[to]){
				mxi = max(mx2[v], mxi);
			}else mxi = max(mx1[v], mxi);
		}
		if(mxi < sz && sz * 2 <= n) mxi = sz;
		calc(to, v, szi, mxi);
		
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 1, x, y; i <n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	calc(1, 0, 0, 0);
	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);	
	}
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}