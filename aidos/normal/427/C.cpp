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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;

vector < int > g[100007], gr[100007];
vector< int > used;
vector<int> order, component;
int n, m; 
void dfs1 (int v) {
	used[v] = true;
	for (int i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (int i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}
int a[111111];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    cin >> m;
	for(int i = 0; i<m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		gr[y].pb(x);
	}
	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
	int ans = 1, mod = 1000000007;
	ll ans2 = 0;
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
			int maxn = inf, ok = 1;
			for(int i = 0; i < component.size(); i++){
				int to = component[i];
				if(a[to] < maxn){
					ok = 1;
					maxn = a[to];
				}
				else if(maxn == a[to]){ok++;}
					
			}
			ans2 += maxn;
			ans = (ans * 1ll * ok) % mod;
			component.clear();
		}
		//cout << ans2 << endl;
	}
	cout << ans2 << " " << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}