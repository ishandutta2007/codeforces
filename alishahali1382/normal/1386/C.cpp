#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, SQ=460;

struct DSU1{
	int par[MAXN], col[MAXN];
	void reset(){
		iota(par, par+MAXN, 0);
		fill(col, col+MAXN, 0);
	}
	DSU1(){
		reset();
	}
	pii get(int x){
		if (par[x]==x) return {x, 0};
		pii p=get(par[x]);
		p.second^=col[x];
		par[x]=p.first;
		col[x]=p.second;
		return p;
	}
	bool join(int u, int v, int w=1){
		pii p1=get(u), p2=get(v);
		if (p1.first==p2.first) return p1.second^p2.second^w;
		par[p1.first]=p2.first;
		col[p1.first]=p1.second^p2.second^w;
		return 0;
	}
};
pair<int*, int> todo[MAXN*10];
int TDO;

struct DSU2{
	int par[MAXN], col[MAXN], sz[MAXN];
	DSU2(){
		iota(par, par+MAXN, 0);
		fill(col, col+MAXN, 0);
		fill(sz, sz+MAXN, 0);
	}
	pii get(int x){
		if (par[x]==x) return {x, 0};
		pii p=get(par[x]);
		p.second^=col[x];
		return p;
	}
	bool join(int u, int v, int w=1){
		pii p1=get(u), p2=get(v);
		int x=p1.first, y=p2.first;
		w^=p1.second^p2.second;
		if (x==y) return w;
		if (sz[x]>sz[y]) swap(x, y);
		todo[TDO++]={par+x, par[x]};
		par[x]=y;
		if (w){
			todo[TDO++]={col+x, 0};
			col[x]=1;
		}
		if (sz[x]==sz[y]){
			todo[TDO++]={sz+y, sz[y]};
			sz[y]++;
		}
		return 0;
	}
};

inline void undo(int x=0){
	while (x<TDO){
		TDO--;
		(*todo[TDO].first)=todo[TDO].second;
	}
}

int n, m, q, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN], ans[MAXN], pref, suff;
DSU1 dsu1;
DSU2 dsu2;
vector<int> Q[MAXN];

void divide(int tl, int tr, int L, int R){
	if (tl>tr) return ;
	
//	cerr<<"divide "<<tl<<' '<<tr<<"   "<<L<<' '<<R<<"\n";
	
	if (L==R){
		for (int i=tl; i<=tr; i++) ans[i]=L;
		return ;
	}
	int TD1=TDO;
	int mid=(tl+tr)>>1;
	for (int i=tl; i<mid; i++) dsu2.join(A[i], B[i]);//assert(!dsu2.join(A[i], B[i]));
	
	if (tl==3 && tr==3){
//		dsu2.join(1, 3);
//		dsu2.join(1, 5);
//		debug(dsu2.join(3, 5))
	}
	
	int TD2=TDO;
	for (int i=R; i>=L; i--) if (dsu2.join(A[i], B[i])){
		ans[mid]=i;
		break ;
	}
//	debug2(mid, ans[mid])
	
	undo(TD2);
//	assert(!dsu2.join(A[mid], B[mid]));
	dsu2.join(A[mid], B[mid]);
	divide(mid+1, tr, ans[mid], R);
	undo(TD1);
	
	for (int i=R; i>ans[mid]; i--) dsu2.join(A[i], B[i]);
	divide(tl, mid-1, L, ans[mid]);
	undo(TD1);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=1; i<=m; i++){
		cin>>A[i]>>B[i];
		if (!pref && dsu1.join(A[i], B[i])) pref=i;
	}
	if (!pref){
		while (q--) cout<<"NO\n";
		return 0;
	}
	dsu1.reset();
	for (int i=m; i; i--){
		if (dsu1.join(A[i], B[i])){
			suff=i;
			break ;
		}
	}
	
//	debug2(pref, suff)
	
	divide(1, pref, suff, m);
//	divide(1, 3, 4, 8);
//	for (int i=1; i<=pref; i++) debug2(i, ans[i])
	
	while (q--){
		int l, r;
		cin>>l>>r;
		if (pref<l || r<suff || r<ans[l]) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
/*
6 8 1
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
4 7

*/