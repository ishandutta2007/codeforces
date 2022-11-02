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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int mod = 1000000007;
int n;
vector < int > g[300300], u[300300];
int dp[300300][3];
int ans[300300];
int binpow(int x, int y){
	if(y == 0) {
		if(x == 0) return 0;
		return 1;
	}
	if(y & 1) {
		return binpow(x, y-1) * 1ll * x % mod;
	}
	return binpow(x * 1ll * x % mod, y/2);
}


void dfs(int x){
	for(int j = 0; j < g[x].size(); j++){
		dfs(g[x][j]);
	}
	
	int &ans1 = dp[x][0];
	int &ans2 = dp[x][1];
	ans2 = 1;
	for(int j  =g[x].size(); j > 0; j--){
		int to = g[x][j-1];
		int cur = 1 + dp[to][1];
		u[x].pb(ans2);
		ans2 = ans2 + (1 + dp[to][1]) * 1ll * ans2 % mod;
		ans2 %=mod;
	}
	reverse(u[x].begin(), u[x].end());
	ans2--;
	if(ans2 < 0) ans2+=mod;
}

void dfs2(int x, int a2){
	{
		int ans2 = a2 + 2;
		int cur =(dp[x][1] + 1) % mod; 
		cur = cur * 1ll * ans2 % mod;
		ans[x] = cur % mod;
//		cout << x <<  " "<< ans2 << endl;
	}
	int ansx = 1;
	for(int j = 0; j < g[x].size(); j++){
		int to  = g[x][j];
		int ans2 = ansx * 1ll * u[x][j] % mod;
    	ans2 = ans2 * 1ll * (a2 + 2) % mod;
    	dfs2(to, (ans2-1 + mod) % mod);
    	ansx = (ansx * 1ll * (dp[to][1] + 2)) % mod;
    }
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 1, x; i < n; i++){
    	scanf("%d", &x);
    	g[x-1].pb(i);
    }
    dfs(0);
    dfs2(0, -1);
    for(int i = 0; i < n; i++){
    	printf("%d ",ans[i]);
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}