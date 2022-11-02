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
vector<int> g[200200];
vector<int> gr[200200];
int nxt[200200][2];
int used[200200][2];
int n, m;

void rdfs(int v, int st){
	if(used[v][st])return;
	used[v][st] = 1;
	for(int i = 0; i < gr[v].size(); i++){
		int to = gr[v][i];
		if(!used[to][st^1]){
			rdfs(to, st^1);
			nxt[to][st^1] = v;
		}
	}
}

int u[200200];

void dfs(int v){
	u[v] = 1;
	forit(it, g[v]){
		int to = *it;
		if(u[to] == 0){
			dfs(to);
		}else if(u[to] == 1){
			printf("Draw\n");
			exit(0);
		}
	}
	u[v] = 2;
}

void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1, k; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0, x; j < k; j++){
			scanf("%d", &x);
			g[i].pb(x);
			gr[x].pb(i);
		}
	}
	int st;
	scanf("%d", &st);
	for(int i = 1; i <= n; i++){
		if(g[i].size()==0){
			rdfs(i, 0);
		}
	}
	if(used[st][1]){
		printf("Win\n");
		vector<int> li;
		int cur = 1;
		while(st != 0){
			li.pb(st);
			st = nxt[st][cur];
			cur ^= 1;
		}
		for(int i = 0; i < li.size(); i++){
			printf("%d%c", li[i], " \n"[i+1 == li.size()]);
		}
		return;
	}
	dfs(st);
	printf("Lose\n");	
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}