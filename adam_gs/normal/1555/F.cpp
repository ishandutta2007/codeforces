#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7, LG=20;
vector<pair<int,int>>V[LIM];
pair<pair<int,int>,int>kraw[2*LIM];
int F[LIM], uzyte[2*LIM], ojciec[LIM], odl[LIM], pierwszy[LIM];
int tr[1<<20], lazy[1<<20], nr[LIM], ciezki[LIM], akt, N=1;
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
	if(fnd(a)==fnd(b)) return false;
	F[fnd(a)]=fnd(b);
	return true;
}
void DFS3(int x, int o) {
	F[x]=1;
	for(auto i : V[x]) if(i.st!=o) {
		odl[i.st]=odl[x]^i.nd;
		DFS3(i.st, x);
	}
}
void DFS(int x, int o) {
	ojciec[x]=o;
	F[x]=1;
	ciezki[x]=-1;
	int ma=0;
	for(auto i : V[x]) if(i.st!=o) {
		odl[i.st]=odl[x]+1;
		DFS(i.st, x);
		F[x]+=F[i.st];
		if(F[i.st]>ma) {
			ma=F[i.st];
			ciezki[x]=i.st;
		}
	}
}
void DFS2(int x, int o) {
	nr[x]=akt;
	++akt;
	if(ciezki[x]!=-1) {
		pierwszy[ciezki[x]]=pierwszy[x];
		DFS2(ciezki[x], x);
	}
	for(auto i : V[x]) if(i.st!=o && i.st!=ciezki[x]) {
		pierwszy[i.st]=i.st;
		DFS2(i.st, x);
	}
}
void spl(int v) {
	tr[2*v]+=lazy[v]/2;
	tr[2*v+1]+=lazy[v]/2;
	lazy[2*v]+=lazy[v]/2;
	lazy[2*v+1]+=lazy[v]/2;
	lazy[v]=0;
}
void upd(int v, int l, int r, int a, int b) {
	if(b<l || a>r) return;
	if(a<=l && r<=b) {
		tr[v]+=(r-l+1);
		lazy[v]+=(r-l+1);
		return;
	}
	if(lazy[v]) spl(v);
	int mid=(l+r)/2;
	upd(2*v, l, mid, a, b);
	upd(2*v+1, mid+1, r, a, b);
	tr[v]=tr[2*v]+tr[2*v+1];
}
int cnt(int v, int l, int r, int a, int b) {
	if(b<l || a>r) return 0;
	if(a<=l && r<=b) return tr[v];
	if(lazy[v]) spl(v);
	int mid=(l+r)/2;
	int ans=cnt(2*v, l, mid, a, b)+cnt(2*v+1, mid+1, r, a, b);
	tr[v]=tr[2*v]+tr[2*v+1];
	return ans;
}
void dodaj(int a, int b) {
	while(pierwszy[a]!=pierwszy[b]) {
		if(odl[pierwszy[a]]>=odl[pierwszy[b]]) {
			upd(1, 0, N-1, nr[pierwszy[a]], nr[a]);
			a=ojciec[pierwszy[a]];
		} else {
			upd(1, 0, N-1, nr[pierwszy[b]], nr[b]);
			b=ojciec[pierwszy[b]];
		}
	}
	int l=nr[a], r=nr[b];
	if(l>r) swap(l, r);
	if(l!=r) upd(1, 0, N-1, l+1, r);
}
int licz(int a, int b) {
	int ans=0;
	while(pierwszy[a]!=pierwszy[b]) {
		if(odl[pierwszy[a]]>=odl[pierwszy[b]]) {
			ans+=cnt(1, 0, N-1, nr[pierwszy[a]], nr[a]);
			a=ojciec[pierwszy[a]];
		} else {
			ans+=cnt(1, 0, N-1, nr[pierwszy[b]], nr[b]);
			b=ojciec[pierwszy[b]];
		}
	}
	int l=nr[a], r=nr[b];
	if(l>r) swap(l, r);
	if(l!=r) ans+=cnt(1, 0, N-1, l+1, r);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	while(N<n) N*=2;
	rep(i, n) F[i]=i;
	rep(i, q) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		kraw[i]={{a, b}, c};
		if(uni(a, b)) {
			V[a].pb({b, c});
			V[b].pb({a, c});
			uzyte[i]=1;
		}
	}
	rep(i, n) F[i]=0;
	rep(i, n) if(!F[i]) DFS3(i, i);
	rep(i, q) {
		if(uzyte[i]) continue;
		if((odl[kraw[i].st.st]^odl[kraw[i].st.nd])==kraw[i].nd) uzyte[i]=-1;
	}
	rep(i, n) if(!ciezki[i]) DFS(i, i);
	rep(i, n) if(!nr[i]) DFS2(i, i);
	rep(i, q) {
		if(uzyte[i]) continue;
		int a=kraw[i].st.st, b=kraw[i].st.nd, w=kraw[i].nd;
		if(licz(a, b)) continue;
		dodaj(a, b);
		uzyte[i]=1;
	}
	rep(i, q) cout << (uzyte[i]==1?"YES":"NO") << '\n';
}