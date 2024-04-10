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
int n, m, k;
set<int> g[200200];
int used[200100];

	set<pii> S;
void del(int v){
	used[v] = 1;
	for(int u: g[v]){
		if(u != v){
			S.erase(mp(g[u].size(), u));
			g[u].erase(v);
			S.insert(mp(g[u].size(), u));
		}
	}
	
}
int cnt = 0;
void dfs(int v){
	used[v] = 1;
	++cnt;
	for(int u:g[v]){
		if(!used[u]){
			dfs(u);
		}
	}
}
pii d[200200];
int ans[200200];
void solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].insert(y);
		g[y].insert(x);
		d[i] = mp(x, y);
	}
	for(int i = 1; i <=n; i++){
		S.insert(mp(g[i].size(), i));
	}
	
	for(int i = m-1; i >= 0; i--){
		while(S.size() > 0 && S.begin()->f < k){
			int v = S.begin()->s;
			S.erase(S.begin());
			del(v);
		}
		ans[i] = S.size();
		if(used[d[i].f] == 1) continue;
		if(used[d[i].s] == 1) continue;
		
		S.erase(mp(g[d[i].f].size(), d[i].f));
		S.erase(mp(g[d[i].s].size(), d[i].s));
		g[d[i].f].erase(d[i].s);
		g[d[i].s].erase(d[i].f);
		
		S.insert(mp(g[d[i].f].size(), d[i].f));
		S.insert(mp(g[d[i].s].size(), d[i].s));
		
		
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
	
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