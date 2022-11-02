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
vector<int> g[300300];
int used[300300];
int T;
int u2[300300];
char c[300300];
int dp[300300][27];
vector<int> ord;
void dfs(int v){
	used[v] = T;
	forit(it, g[v]){
		if(!used[*it]){
			dfs(*it);
		}
		else if(!u2[*it]){
			cout << -1 << endl;
			exit(0);
		}
	}
	ord.pb(v);
	u2[v] = T;
}  
int n;
int m;
void solve(){
	scanf("%d%d", &n, &m);
	scanf("%s", c+1);
	for(int i = 0, x, y; i < m; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
	}
	T++;
	for(int i = 1; i <= n;i++){
		if(!used[i]){
			dfs(i);
		}
	}
	for(int i = 0; i < ord.size(); i++){
		int v = ord[i];
		for(int j = 0; j < 26; j++) dp[v][j] = 0;
		forit(it, g[v]){		
			for(int j = 0; j < 26; j++) dp[v][j] = max(dp[v][j], dp[*it][j]);
		}
		dp[v][c[v]-'a']++;
	}
	int ans = 0;
	for(int i =1; i <=n; i++){
		for(int j = 0; j < 26; j++) ans = max(ans, dp[i][j]);
	}

	cout << ans << endl;
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