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


vector<int> li[22];
int a[22][22];
int n;
char c[111], t[111];

int ok[400400];


struct edge{
	int from, to, cap, flow;
	edge(){}
	edge(int _from, int _to, int _cap, int _flow){
		from = _from;
		to = _to;
		cap = _cap;
		flow = _flow;
	}	
};


int S, T;
vector<int> g[200900];
vector<edge> e;
int d[200900];
int ptr[200900];
void add_edge(int from, int to, int cap){
	g[from].pb(e.size());
	e.pb(edge(from, to, cap, 0));
	g[to].pb(e.size());
	e.pb(edge(to, from, 0, 0));
}
bool bfs(){
	for(int i = 0; i <= T; i++){
		d[i] = -1;
		ptr[i] = 0;
	}
	queue<int> q;
	d[S] = 0;
	q.push(S);
	while(q.size() > 0 && d[T] == -1){
		int v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int id = g[v][i];
			int to = e[id].to;
			if(e[id].cap > e[id].flow && d[to] == -1){
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	return d[T] != -1;
}


int dfs(int v, int flow){
	if(flow == 0) return 0;
	if(v == T) return flow;
	while(ptr[v] < g[v].size()){
		int id = g[v][ptr[v]];
		int to = e[id].to;
		if(d[to] == d[v] + 1 && e[id].flow < e[id].cap){
			int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
			if(pushed){
				e[id].flow += pushed;
				e[id^1].flow-=pushed;
				return pushed;
			}
		}
		ptr[v]++;
	}
	return 0;
}



int dinic(){
	int flow = 0;
	while(bfs()){
		int pushed = dfs(S, inf);
		while(pushed){
			flow += pushed;
			pushed = dfs(S, inf);
		}
	}
	return flow;
}

vector<pii> ans;
pii cure[400400];

vector<int> path;
int dfs2(int v){
	if(v == T) return 1;
	while(ptr[v] < g[v].size()){
		int id = g[v][ptr[v]];
		int to = e[id].to;
		if(e[id].cap > 0 && e[id].flow >0 && dfs2(to)){
			e[id].flow--;
			path.pb(v);
			return 1;
		}
		ptr[v]++;
	}
	return 0;
}
int check(int x, int cc = 0){
	T = n + 500;
	S = 0;
	e.clear();
	for(int i = 0; i <= T; i++)
		g[i].clear();
	for(int i = 1; i <= 6; i++){
		if(li[i].size() == 0) continue;
		int st = 0;
		if(i == x) st = 1;
		for(int j = st; j < li[i].size(); j++){
			add_edge(li[i][j], n + i, 1);
			add_edge(S, li[i][j], 1);
		}
	}
	int sz = n + 8; 
	for(int i = 1; i <= 6; i++)
		for(int j = i+1; j <= 6; j++){
			add_edge(n + i, sz, a[i][j]);
			add_edge(n + j, sz, a[i][j]);
			add_edge(sz, T, a[i][j]);
			cure[sz] = mp(i, j);
			sz++;
		}
	
	int cntt =dinic();
	if(cc){
		for(int i = 0; i <= T; i++)
			ptr[i] = 0;
		path.clear();
		int com=0;
		int vis=  0;
		while(dfs2(S)){
			int u = 0;
			int xx = 0;
			int cur = 0;
			for(int i = 0; i < path.size(); i++){
				if(path[i] >= 1 && path[i] <= n) u = path[i];
				if(path[i] >= n + 8 && path[i] < T) xx = path[i];
				if(path[i] > n && path[i] < n + 8) cur = path[i];
			}
			int st = (cur-n) ^ cure[xx].f ^ cure[xx].s;
			if(li[st].size()>0){
				int v = li[st][0];
				ans.pb(mp(u, v));
			}
			path.clear();
		}
	}
	return cntt;
}
int pp[300900];

int get(int v){
	if(pp[v] == v) return v;
	return pp[v] = get(pp[v]);
}
bool merge(int u, int v){
	u = get(u);
	v = get(v);
	if(u == v) return 0;
	pp[u] = v;
	return 1;	
}


void solve(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%s%s", c, t);
		int l1 = strlen(c);
		int l2 = strlen(t);
		if(l1 > l2) swap(l1, l2);
		a[l1][l2]++;
	}
	int mx = 0;
	for(int i = 1; i <= n; i++){
		int j = i;
		int c = 0;
		while(j > 0){
			j/=10;
			c++;
		}
		mx = c;
		li[c].pb(i);
	}
	int cnt = n-1;
	
	for(int i = 1; i < 10; i++){
		if(li[i].size() > 0){
			if(a[i][i]> li[i].size() - 1){
				printf("-1");
				return;
			}
			while(a[i][i] > 0){
				int x=li[i].back();
				li[i].pop_back();
				ans.pb(mp(x, li[i].back()));
				cnt--;
				a[i][i]--;
			}
		}
	}
	vector<pii> cur;
	for(int i = 1; i <= mx; i++){
		if(check(i) != cnt){
			printf("-1");
			return;
		}
	}
	//cout << 
	cur = ans;
	for(int j = 1; j <= mx; j++){
		check(j, 1);// << endl;
		for(int i = 1; i <= n; i++)
			pp[i] = i;
		
		bool good = 1;
		for(int i = 0; i < ans.size(); i++){
			good &= merge(ans[i].f, ans[i].s);
		}
		if(good){
			for(int i = 0; i < ans.size(); i++)
				printf("%d %d\n", ans[i].f, ans[i].s);
			return;
		}
		ans = cur;
	}
	printf("-1\n");
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