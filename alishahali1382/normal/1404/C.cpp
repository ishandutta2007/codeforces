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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], fen[MAXN], ans[MAXN];
int lazy[MAXN<<2];
pii seg[MAXN<<2];
vector<pii> Q[MAXN];

void add(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}
void add_lazy(int id, int val){
	lazy[id]+=val;
	seg[id].first+=val;
}
void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}
void Set(int id, int tl, int tr, int pos, pii p){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=p;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, p);
	Set(id<<1 | 1, mid, tr, pos, p);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}
void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}
pii Build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={inf, tl};
	int mid=(tl+tr)>>1;
	return seg[id]=min(Build(id<<1, tl, mid), Build(id<<1 | 1, mid, tr));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		Q[x].pb({y, i});
	}
	Build(1, 1, n+1);
	for (int i=n; i; i--){
//		debug(i)
		if (A[i]<=i){
			Set(1, 1, n+1, i, pii(i-A[i], i));
			while (seg[1].first<=0){
				int pos=seg[1].second;
				add(pos, +1);
//				debug(pos)
				Add(1, 1, n+1, pos+1, n+1, -1);
				Set(1, 1, n+1, pos, pii(inf, pos));
			}
		}
		for (pii p:Q[i-1]) ans[p.second]=get(n-p.first);
	}
	
	for (int i=1; i<=m; i++) cout<<ans[i]<<"\n";
	
	return 0;
}
/*
13 1
2 2 3 9 5 4 6 5 7 8 3 11 13
0 0

*/