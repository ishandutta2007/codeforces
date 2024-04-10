#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100100, inf = 1e9, mod = 1e9 + 7, K = 600100;

struct node{
	ll h1, h2;
	node *l, *r;
	node(){
		h1 = h2 = 0;
		l = NULL;
		r = NULL;
	}
	node(node *&v){   
		h1 = v -> h1;
		h2 = v -> h2;
		l = v -> l;
		r = v -> r;
	}
};

node *t[N];
ll p1[K], p2[K], b1 = 37, b2 = 41, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

void build(node *&v, int tl, int tr){
	v = new node();
	if(tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	build(v -> l, tl, tm);
	build(v -> r, tm + 1, tr);                       
}
void upd(node *&v, int tl, int tr, int pos, int val){
	v = new node(v);
	if(tl == tr){
		v -> h1 = v -> h2 = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
		upd(v -> l, tl, tm, pos, val);
	else
		upd(v -> r, tm + 1, tr, pos, val);                       
	v -> h1 = (v -> l -> h1 * p1[tr - tm] + v -> r -> h1) % mod1;
	v -> h2 = (v -> l -> h2 * p2[tr - tm] + v -> r -> h2) % mod2;	
}
bool cmp(node *&v, node *&u, int tl, int tr){
	if(tl == tr)
		return v -> h1 >= u -> h1;
	int tm = (tl + tr) >> 1;
	if(v -> l -> h1 == u -> l -> h1 && v -> l -> h2 == u -> l -> h2)
		return cmp(v -> r, u -> r, tm + 1, tr);
	return cmp(v -> l, u -> l, tl, tm);
}

vector< pii > g[N], G[N], GR[N];
int n, m, cnt[N], cd[N], sz[N], dist[N];
ll ans[N];

void add(int v, int k){
	if(k >= 10)
		add(v, k / 10);
	ans[v] = (ans[v] * 10 + (k % 10)) % mod;
	upd(t[v], 1, K, ++sz[v], k % 10);
}
int ff(int v, int u, int w){
	sz[0] = sz[u];
	t[0] = new node(t[u]);
	add(0, w);
	return cmp(t[v], t[0], 1, K);
}
int main()
{
	p1[0] = p2[0] = 1;
	for(int i = 1; i < K; i++){       
		p1[i] = p1[i - 1] * b1 % mod1;
		p2[i] = p2[i - 1] * b2 % mod2;
	}
	build(t[0], 1, K);
	for(int i = 1; i < N; i++){
		cd[i] = cd[i / 10] + 1; 
		t[i] = new node(t[0]);		
	}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int v, u;
		scanf("%d %d", &v, &u);
		g[v].pb({u, i});
		g[u].pb({v, i});
	}

	{
		for(int i = 1; i <= n; i++)
			dist[i] = inf;
		dist[1] = 0;
		set< pii > st;
		st.insert({dist[1], 1});
		while(!st.empty()){
			int v = st.begin() -> s;
			st.erase(st.begin());
			for(auto it : g[v]){
				int to = it.f;
				int w = it.s;
				if(dist[to] > dist[v] + cd[w]){
					st.erase({dist[to], to});
					dist[to] = dist[v] + cd[w];
					st.insert({dist[to], to});
				}
			}
		}
	}
	set< int > st;
	for(int v = 1; v <= n; v++)
		for(auto it : g[v]){
			int to = it.f;
			int w = it.s;
			if(dist[to] == dist[v] + cd[w]){
				cnt[to]++;
				G[v].pb({to, w});
				GR[to].pb({v, w});
			}
		}                        
	for(int v = 1; v <= n; v++)
		if(cnt[v] == 0)
			st.insert(v);
	while(!st.empty()){
		int v = *st.begin();
		st.erase(st.begin());
		for(auto to : G[v]){
			cnt[to.f]--;
			if(cnt[to.f] == 0)
				st.insert(to.f);								
		}
		bool k = 0;
		for(auto it : GR[v]){
			int pr = it.f;
			int w = it.s;
            if(k == 0){
				sz[v] = sz[pr];
				ans[v] = ans[pr];
				t[v] = new node(t[pr]);
				add(v, w);
			}else if(ff(v, pr, w)){
				sz[v] = sz[pr];
				ans[v] = ans[pr];
				t[v] = new node(t[pr]);
				add(v, w);
			}	
			k = 1;
		} 		
	}
	for(int i = 2; i <= n; i++)
		printf("%lld\n", ans[i]);
	return 0;
}