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

ll d1[100100];
ll d2[100100];
ll d3[100100];
ll d4[100100];

int a[100100];
vector < int > g[100100];
ll ans = 0;
int n;
void dfs(int v, int p){
	d1[v] = a[v];
	d2[v] = a[v];
	d3[v] = a[v];
	d4[v] = 0;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		ll temp1 = max(d1[v], d1[to]+a[v]);
		ll temp2 = max(d2[v], d2[to]+a[v]);
		ll temp3 = d3[v];
		ll temp4 = max(max(d4[v], d4[to]), d3[to]);
		ans = max(d1[v] + d2[to], ans);
		ans = max(d1[v] + d1[to], ans);
		ans = max(d1[v] + d3[to], ans);
		ans = max(d1[v] + d4[to], ans);
		ans = max(d2[v] + d1[to], ans);
		ans = max(ans, max(d3[v], d4[v]) + max(d3[to], d4[to]));

		
		temp2 = max(temp2, d1[to] + d4[v] + a[v]);
		temp2 = max(temp2, max(d3[to], d4[to]) + d1[v]);
		temp3 = max(temp3, d1[to] + d1[v]);
		d1[v] = temp1;
		d2[v] = max(max(temp2, max(temp3, temp4)), temp1);
		d3[v] = max(temp1, max(temp4, temp3));
		d4[v] = temp4;
	}
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 1, x, y; i < n; i++){
    	cin >> x >> y;
    	g[x-1].pb(y-1);
    	g[y-1].pb( x - 1);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++)
    	ans = max(ans, d1[i]);

    for(int i = 0; i < n; i++)
    	ans = max(ans, d2[i]);

    for(int i = 0; i < n; i++)
    	ans = max(ans, d3[i]);

    for(int i = 0; i < n; i++)
    	ans = max(ans, d4[i]);
    cout << ans << endl;

    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}