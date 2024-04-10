#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

const int N = 100500, LOG = 18, mod = 1000000007, mm = mod + 2;

struct pii{
	int a, b;
	pii(){
		a = b = 0;
	}
	pii(int x, int y){
		a = x;
		b = y;
	}
	pii operator *(pii x){
		return {1ll * a * x.a % mod, 1ll * b * x.b % mm};
	}
    pii operator +(pii x){
		return {(a + x.a) % mod, (b + x.b) % mm};
	}
    pii operator -(pii x){
		return {(a - x.a + mod) % mod, (b - x.b + mm) % mm};
	}
};
vector< pair<int, int> > g[N];
int n, m, S, depth[N], up[N], pr[N];
vector< pair< pair<int, int>, int> > e;
bool used[N];


ll binpow(ll x, ll p){
	ll res = 1;
	while(p){
		if(p & 1)
			res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}
ll inv(ll x){
	return binpow(x, mod - 2);
}
void ff(vector< pii > &a){
	for(int i = 0; i < LOG; i++){
		for(int j = 0; j < (1 << LOG); j++){
			if((j >> i) & 1){
				pii x = a[j ^ (1 << i)];
				pii y = a[j];
				a[j ^ (1 << i)] = x + y;
				a[j] = x - y;
			}
		}
	}
}
void dfs(int v, int p){
	used[v] = 1;
	for(auto it : g[v]){
		int to = it.f; 
		int w = it.s;
		if(to == p)
			continue;
		if(used[to]){
			if(depth[v] > depth[to])
				e.pb({{v, to}, w});
		}else{
			up[to] = w;
			pr[to] = v;
			depth[to] = depth[v] + 1;
			dfs(to, v);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		g[v].pb({u, w});
		g[u].pb({v, w});
		S ^= w;
	}			
	dfs(1, -1);
	vector< pii > a(1 << LOG, pii());
	a[S].a++;
	a[S].b++;
	ff(a);
	for(auto it : e){
		int v = it.f.f;
		int u = it.f.s;
		int w = it.s;
		vector< pii > b(1 << LOG, pii());
		b[w].a++;
		b[w].b++;
		while(v != u){   
			b[up[v]].a++;
			b[up[v]].b++;
			v = pr[v];
		}
		ff(b);
		for(int i = 0; i < (1 << LOG); i++)
			a[i] = a[i] * b[i];
    }
	ff(a);
	for(int i = 0; i < (1 << LOG); i++){
		if(a[i].a || a[i].b){
			printf("%d %d\n", i, a[i].a * inv(binpow(2, LOG)) % mod);
			return 0;
		}
	}
	return 0;
}