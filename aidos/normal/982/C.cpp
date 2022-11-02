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

const int inf = (1ll << 25) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
vector< int > g[maxn];
int n;
int sz[maxn];

void dfs(int v, int p) {
	sz[v] = 1;
	for(int to: g[v]) {
		if(to == p) continue;
		dfs(to, v);
		sz[v] += sz[to];
	}
}


void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	if(n % 2 == 1) {
		cout << -1 << "\n";
		return;
	}
	dfs(1, 0);
	int ans = -1;
	for(int i = 1; i <= n; i++) {
		if(sz[i] % 2 == 0) ans++;
	}
	cout << ans << "\n";

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