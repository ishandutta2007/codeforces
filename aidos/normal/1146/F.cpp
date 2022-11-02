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
int n;
vector<int> g[200200];
ll dp[200200][2];
ll mod = 998244353;

ll t[20];
ll val[200200];

void dfs(int v){
	if(g[v].size() == 0) {
		dp[v][0] = 1;
		dp[v][1] = 1;
	}
	else{
		if(g[v].size() == 1) {
			dfs(g[v][0]);
			dp[v][0] = dp[g[v][0]][0];
			dp[v][1] = dp[g[v][0]][1];
		}else {
			for(int i = 0; i < g[v].size(); i++){
				int to = g[v][i];
				dfs(to);
				
				if(i == 0) {
					dp[v][0] = dp[to][0];
					dp[v][1] = dp[to][1];				
				}
				else {
					for(int j = 0; j < 2; j++){
						t[j] = 0;
					}
					for(int j = 0; j < 2; j++){
						for(int k = 0; k < 2; k++){
							t[j|k] = (t[j|k] + dp[v][j] * 1ll * dp[to][k]) % mod;
						}
					}
					for(int j = 0; j < 2; j++) dp[v][j] = t[j];
				}
			}
			dp[v][0] = (dp[v][1]  + dp[v][0]) % mod;
			for(int i = 0; i < g[v].size(); i++) val[i] = 1;
			ll cur = 1;
			for(int i = 0; i < g[v].size(); i++) {
				int to = g[v][i];
				val[i] = cur;
				cur = (cur * dp[to][0]) % mod;
			}
			cur = 1;
			for(int i = (int)g[v].size()-1; i >= 0; i--) {
				int to = g[v][i];
				val[i] = (val[i] * cur) % mod;
				cur = (cur * dp[to][0]) % mod;
			}
			for(int i = 0; i < g[v].size(); i++){
				int to = g[v][i];
				dp[v][0] = (dp[v][0] + (mod - val[i] % mod * dp[to][1] % mod)) % mod;
			}
		}
	}
}

void solve(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		g[x].pb(i);
	}
	dfs(1);
	
	printf("%d\n", (int)dp[1][0]);
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