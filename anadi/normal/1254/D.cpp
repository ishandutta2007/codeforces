#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int T = 1 << 18;

const int MX = 998244353;
const LL INF = 1LL * MX * MX;

int n, q;
vector <int> G[N];

int prv[N];
int favCh[N];
vector <int> heavy[N];

LL cnt[N];
LL global = 0;

int sz[N];
int pre[N], post[N];
LL tree[T + T + 7];

void updateAll(int u, int p, int val){
	heavy[u].push_back(val);
	for(auto v: G[u])
		if(v != p)
			updateAll(v, u, val);
}

int dfs(int u, int p){
	static int Time = 0;
	pre[u] = ++Time;
	
	prv[u] = p;
	sz[u] = 1;

	for(auto v: G[u])
		if(v != p)
			sz[u] += dfs(v, u);
	
	favCh[u] = -1;
	for(auto v: G[u])
		if(v != p && (favCh[u] == -1 || sz[favCh[u]] < sz[v]))
			favCh[u] = v;
	
	for(auto v: G[u])
		if(v != p && v != favCh[u])
			updateAll(v, u, v);
	
	post[u] = Time;
	return sz[u];
}

LL ask(int x){
	LL ret = 0;
	x += T;

	while(x){
		ret += tree[x];
		x >>= 1;
	}
	
	return ret;
}

void add(int from, int to, LL v){
	from += T, to += T;
	while(from <= to){
		if(from & 1)
			tree[from] += v;
		if(!(to & 1))
			tree[to] += v;
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
}

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a) % MX;
		
		b >>= 1;
		a = (1LL * a * a) % MX;
	}
	
	return ret;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	while(q--){
		int t, v;
		scanf("%d %d", &t, &v);
		
		if(t == 1){
			int d;
			scanf("%d", &d);
			
			global += 1LL * d * sz[v];
			cnt[v] += d;
			add(pre[favCh[v]], post[favCh[v]], 1LL * d * (n - sz[favCh[v]]) - 1LL * d * sz[v]);
		}
		else{
			LL ans = global + 1LL * cnt[v] * (n - sz[v]);
			ans += ask(pre[v]);

			for(auto t: heavy[v]){
//				printf("%d %d -> %d %lld\n", v, t, prv[t], cnt[prv[t]]);
				ans += 1LL * cnt[prv[t]] * (n - sz[t]) - 1LL * cnt[prv[t]] * sz[prv[t]];
			}
			
			ans = ((ans % MX) + MX) % MX;
//			printf("%lld\n", ans);
			printf("%lld\n", (ans * fast(n, MX - 2)) % MX);
		}
	}

	return 0;
}