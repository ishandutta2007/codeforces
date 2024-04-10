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

vector<int> g[200100];
ll dp[200200][7];
ll cnt[200200][7];
ll a[11];
ll b[11];
int k;
int n;
ll ans = 0;
void dfs(int v, int p){
	cnt[v][0]++;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		for(int j = 0; j < k - 1; j++){
			a[j+1] = dp[to][j];
			b[j+1] = cnt[to][j];
		}
		a[0] = dp[to][k-1] + cnt[to][k-1];
		b[0] = cnt[to][k-1];
		
		for(int ii = 0; ii < k; ii++){
			for(int jj = 0; jj < k; jj++){
				ll x = 0;
				if(ii + jj > k) x = 2;
				else if(ii + jj > 0) x = 1;
				else x = 0;
				ans += a[ii] * cnt[v][jj] + b[ii] * dp[v][jj] + x * cnt[v][jj] * b[ii]; 
			}
		}
		for(int ii = 0; ii < k; ii++){
			cnt[v][ii] += b[ii];
			dp[v][ii] += a[ii];
		}
	}
}
void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 1, x, y; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
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