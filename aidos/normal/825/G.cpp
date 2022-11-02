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

int n, q;
vector<int> g[1000100];
int gg[1000100];
int p[1000100];
int mi = inf;
bool used[1000100];

void dfs(int v, int pa){
	p[v] = pa;
	gg[v] = v;
	if(pa) gg[v] = min(gg[v], gg[pa]);
	for(int i = 0; i < g[v].size(); ++i){
		int to = g[v][i];
		if(to == pa) continue;
		dfs(to, v);
	}
}
int get(int v){
	int ans = mi;
	
	ans = min(ans, gg[v]);
	return ans;
}
void go(int v){
	while(v){
		if(used[v]) return;
		mi = min(v, mi);
		used[v] = 1;
		v = p[v];
	}
}
void solve(){
	scanf("%d%d", &n, &q);
	for(int i =1, x, y; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	int last = 0;
	for(int i = 0, t, x; i < q; i++){
		scanf("%d%d", &t, &x);
		x = (x + last) % n + 1;
		if(!i){
			dfs(x, 0);
		}
		if(t == 1){
			go(x);
		}
		else {
			int ans = get(x);
			printf("%d\n", ans);
			last = ans;
		}
	}
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}