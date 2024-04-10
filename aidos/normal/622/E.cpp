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

const int inf = (1 << 29) - 1;
const int maxn = (int)5e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
vector<int> g[maxn];
vector<int> ord;
void dfs(int v, int p, int lev) {
	if(g[v].size() == 1) ord.pb(lev);
	for(int to: g[v]) {
		if(to != p) dfs(to, v, lev+1);
	}
}
void solve(){
	cin >> n;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int ans = 0;
	for(int i = 0; i < g[1].size(); i++) {
		ord.clear();
		dfs(g[1][i], 1, 1);
		sort(all(ord));
		int last = 0;
		for(int j = 0; j < ord.size(); j++) last = max(last + 1, ord[j]);
		ans = max(ans, last);
	}
	cout << ans << "\n";
}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}