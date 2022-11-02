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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
pii a[100100];
int col[100100];
int u[100100];
vector<pii> g[100100];
int k;
vector<int> ans;
void dfs(int v) {
	u[v] = 1;
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].f;
		int id = g[v][i].s;
		if(!u[to]) {
			dfs(to);
			ans.pb(id);
		}
	}
}
int cnt = 0;
int was[100100];
void solve(){
	cin>>n >> k;
	for(int i = 1; i <= k; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
		a[i] = mp(u, v);
	}
	for(int i = 1; i <= n; i++) if(!u[i]) dfs(i);
	cout << k - ans.size() << "\n";
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