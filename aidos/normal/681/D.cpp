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


int tin[100100], tout[100100];
int timer = 0;
int used[100100];
vector<int> g[100100];
vector<int> gr[100100];
int n, m;
int pa[100100];
int a[100100];
int b[100100];
int con[100100];
void dfs(int v){
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		dfs(to);
		con[v] |= con[to];
	}
	tout[v] = timer++;
}
vector<int> li;

void top_sort(int v){
	used[v] = 1;
	for(int i = 0; i < gr[v].size(); i++){
		int to = gr[v][i];
		if(!used[to]) top_sort(to);
	}
	li.pb(v);
}

void dfs2(int v, int x){
	used[v] = 1;
	b[v] = x;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(!used[to]) dfs2(to, x);
	}
}
void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 0, x, y;i < m; i++){
		scanf("%d %d", &x, &y);
		g[x].pb(y);
		pa[y] = x;
	}
	for(int i = 1; i<=n; i++){
		scanf("%d", &a[i]);
		con[a[i]] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(pa[i]) continue;
		dfs(i);
	}
	for(int i = 1; i <= n; i++){
		if(pa[i] == 0)continue;
		if(con[i]) {
			gr[pa[i]].pb(i);
		}
	}
	for(int i = 1; i<= n; i++){
		if(used[i]) continue;
		top_sort(i);
	}
	for(int i = 1;i <= n; i++)
		con[i] = 0;
	for(int i = 1; i<= n; i++){
		con[a[i]] = 1;
	}
	vector<int> cur;
	for(int i = 0; i < li.size(); i++){
		if(con[li[i]]) cur.pb(li[i]);
	}
	li = cur;
	for(int i = 1; i<=n;i++)
		used[i] = 0;
	for(int i = 0; i < li.size(); i++){
		if(used[li[i]]) continue;
		dfs2(li[i], li[i]);
	}	
	for(int i = 1; i <= n; i++){
		if(a[i] == b[i]) continue;
		cout << -1 << endl;
		return;
	}
	printf("%d\n", li.size());
	for(int i = 0; i < li.size(); i++){
		printf("%d\n", li[i]);
	}
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}