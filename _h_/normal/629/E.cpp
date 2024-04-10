#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

vector<vi> gr, ch, hopp;
vi par, sz, h;
vl sum, mus;

void init(int v){
	int ix = 0, p = par[v];
	while(p >= 0){
		hopp[v].pb(p);
		if(ix >= hopp[p].size()) break;
		p = hopp[p][ix++];
	}
	sz[v] = 1;
	for(int c : gr[v])
		if(c != par[v]){
			par[c] = v;
			h[c] = h[v]+1;
			ch[v].pb(c);
			init(c);
			sum[v] += sum[c]+sz[c];
			sz[v] += sz[c];
		}
}

int upp(int a, int d){
	for(int ix = 0; d > 0; ix++) {
		if(d%2 == 1)
			a = hopp[a][ix];
		d /= 2;
	}
	return a;
}

int lca(int a, int b){
	if(h[b] < h[a]) swap(a,b);
	b = upp(b, h[b]-h[a]);
	if(a == b) return a;
	for(int ix = hopp[a].size()-1; ix >= 0; --ix){
		if(ix >= hopp[a].size()) continue;
		int a1 = hopp[a][ix];
		int b1 = hopp[b][ix];
		if(a1 != b1){
			a = a1;
			b = b1;
		}
	}
	return par[a];
}

void init2(int v){
	int p = par[v];
	mus[v] += mus[p] + sz[0]-sz[p]+1;
	for(int c : ch[p]) if(c != v){
		mus[v] += sum[c]+2*sz[c];
	}
	for(int c : ch[v]) init2(c);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	gr.resize(n);ch.resize(n);hopp.resize(n);par.resize(n);
	sz.resize(n);sum.resize(n);h.resize(n);mus.resize(n);
	rep(_,0,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		--a,--b;
		gr[a].pb(b), gr[b].pb(a);
	}
	par[0] = -1;
	init(0);
	for(int c : ch[0])
		init2(c);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		--u,--v;
		int l = lca(u,v);
		int d = h[v]+h[u]-2*h[l];
		if(l == v) swap(u,v);
		double x;
		if(l == u){
			u = upp(v, h[v]-h[u]-1);
			x = (double)mus[u]/(sz[0]-sz[u]) - 1;
		} else {
			x = (double)sum[u]/sz[u];
		}
		printf("%.9lf\n",d+(double)sum[v]/sz[v]+1+x);
	}
}