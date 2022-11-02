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

int a[200200];
int n, m, h;
vector<int> g[400400];
int col[200200];

vector<int> gr[400400], ord;
int used[400400];
int F= 0;
void add_edge(int i, int j, int u, int v){
	if((u+1) % h == v){
		g[i].pb(j);
	}
	if((v + 1) % h == u){
		g[j].pb(i);
	}
}

void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < gr[v].size(); i++){
		int to = gr[v][i];
		if(!used[to]) dfs(to);
	}
	ord.pb(v);
}

vector<int> li;
int ok;
void dfs2(int v, int cc){
	used[v] = 1;
	col[v] = cc;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(!used[to]) dfs2(to, cc);
		else if(col[to] != cc){
			ok = 0;
		}
	}
	li.pb(v);
}
void solve(){
	scanf("%d%d%d", &n, &m, &h);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1, x, y; i <= m; i++){
		scanf("%d%d", &x, &y);
		add_edge(x, y, a[x], a[y]);
	}
	for(int i = 1; i <= n; i++){
		
		for(int j = 0; j < g[i].size(); j++){
			int to = g[i][j];
			gr[to].pb(i);
		}
	}
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			dfs(i);
		}
		
	}
	memset(used, 0, sizeof used);
	reverse(all(ord));
	int cc = 1;
	vector<int> ans;
	int cur_ans = inf;
	for(int i = 0; i < ord.size(); i++){
		int v = ord[i];
		if(!used[v]){
			ok = 1;
			li.clear();
			dfs2(v, cc);
			cc++;
			if(ok && cur_ans > li.size()) {
				cur_ans = li.size();
				ans = li;
			}
		}
	}
	printf("%d\n", (int)cur_ans);
	forit(it, ans){
		printf("%d ", *it);
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