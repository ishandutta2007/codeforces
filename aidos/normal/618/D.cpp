#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

vector < int > g[200200];
int a, b;
int n;
int mx = 0;
int dp[200200][4];
int dfs(int v, int p, int cd){
	int &res = dp[v][cd];
	if(res != -1) return res;
	res = 0;
	int sum = 0;
	for(int x : g[v]){
		if(x == p) continue;
		sum += dfs(x, v, 0);
	}
	if(cd == 0){
		res = sum;
		int mx1 = -10000000;
		int ind = -1;
		for(int x : g[v]){
			if(x == p) continue;
			int cc = dfs(x, v, 1) - dfs(x, v, 0);
			res = max(sum + cc + 1, res);
			if(cc > mx1) {
				mx1 = cc;
				ind = x;
			}
		}
		int mx2 = -10000000;
		int ind2 = -1;
		for(int x : g[v]){
			if(x == p|| x == ind) continue;
			int cc = dfs(x, v, 1) - dfs(x, v, 0);
			if(cc > mx2) {
				mx2 = cc;
				ind2 = x;
			}
		}
		if(ind2 != -1){
			res = max(res, sum  + mx1 + mx2 + 2);
		}
	}
	else {
		res= max(sum, 0);
		for(int x : g[v]){
			if(x == p) continue;
			int cur = sum - dfs(x, v, 0) + dfs(x, v, 1);
			res= max(cur+1, res);
		}
	}
	return res;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> a >> b;
    for(int i = 1; i  < n; i++){
    	int x, y;
    	cin >> x >> y;
    	g[x].pb( y );
    	g[y].pb( x );
    }
    if(a < b) {
    	memset(dp, -1, sizeof dp);
    	int cnt = dfs(1, 0, 0);
    	cout << cnt *1ll * a + b *1ll * (n-cnt-1) << endl;
    }
    else {
    	int cur = -1;
    	for(int i = 1; i <= n; i++){
    		if(g[i].size() == n-1) cur = i;
    	}
    	if(cur != -1) cout << b * 1ll * (n - 2) + a << endl;
    	else cout << b * 1ll * (n-1) << endl;
    }
    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}