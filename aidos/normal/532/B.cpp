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


vector < int > g[300100];

ll ans = 0;
int a[300100];

int n;
pll dfs(int v){
	ll cur = -1000000000000000ll;
	ll cur2 = -1000000000000000ll;
	for(int i = 0; i < g[v].size(); i++){
		pll tt = dfs(g[v][i]);
		ll xx = max(cur + tt.s, cur2 + tt.f);
		ll yy = max(cur + tt.f, cur2 + tt.s);
		cur = max(xx, cur);
		cur2 = max(yy, cur2);
		cur = max(cur, tt.f);
		cur2 = max(tt.s, cur2);
	}
	cur = max(a[v] + 0ll, cur);
	cur = max(a[v]+cur2, cur);
	
	return mp(cur,cur2);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    for(int i = 1, x;  i<= n; i++){
    	scanf("%d %d", &x, &a[i]);
    	if( i > 1) g[x].pb(i);
    }
    pll xx = dfs(1);
    cout << max(xx.f, xx.s) << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}