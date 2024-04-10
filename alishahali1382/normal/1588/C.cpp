#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
pll seg[MAXN<<2][2];
ll lazy[MAXN<<2];

inline void add_lazy(int id, ll val){
	seg[id][0].first-=val;
	seg[id][1].first+=val;
	lazy[id]+=val;
}
inline void shift(int id){
	if (lazy[id]){
		add_lazy(id<<1, lazy[id]);
		add_lazy(id<<1 | 1, lazy[id]);
		lazy[id]=0;
	}
}
inline pll combine(pll x, pll y){ return (x.first==y.first?pll(x.first, x.second+y.second):min(x, y));}
void Add(int id, int tl, int tr, int l, int r, ll val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id][0]=combine(seg[id<<1][0], seg[id<<1 | 1][0]);
	seg[id][1]=combine(seg[id<<1][1], seg[id<<1 | 1][1]);
}
int BS(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l || min(seg[id][0], seg[id][1]).first>=0) return tl-1;
	if (tr-tl==1) return tl;
	shift(id);
	int mid=(tl+tr)>>1, res=BS(id<<1 | 1, mid, tr, l, r);
	if (mid<=res) return res;
	return BS(id<<1, tl, mid, l, r);
}
void Build(int id, int tl, int tr){
	lazy[id]=0;
	seg[id][0]=seg[id][1]=seg[0][0];
	if (tr-tl==1){
		if (tl&1) seg[id][1]={/*A[tl]*/0, 1};
		else seg[id][0]={0/*-A[tl]*/, 1};
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id][0]=combine(seg[id<<1][0], seg[id<<1 | 1][0]);
	seg[id][1]=combine(seg[id<<1][1], seg[id<<1 | 1][1]);
}
pll Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0][0];
	if (l<=tl && tr<=r) return combine(seg[id][0], seg[id][1]);
	shift(id);
	int mid=(tl+tr)>>1;
	return combine(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}
void Main(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	ll ans=0;
	Build(1, 1, n+1);
	for (int r=1; r<=n; r+=2){
		Add(1, 1, n+1, 1, r, A[r]-A[r-1]);
		Add(1, 1, n+1, r, r+1, A[r]);
		int pos=BS(1, 1, n+1, 1, r+1);
		pll p=Get(1, 1, n+1, pos+1, r+1);
		if (!p.first) ans+=p.second;
	}
//	debug(ans)
	Build(1, 1, n+1);
	for (int r=2; r<=n; r+=2){
		Add(1, 1, n+1, 1, r, -A[r]+A[r-1]);
		Add(1, 1, n+1, r, r+1, -A[r]);
		int pos=BS(1, 1, n+1, 1, r+1);
		pll p=Get(1, 1, n+1, pos+1, r+1);
		if (!p.first) ans+=p.second;
	}
//	debug(ans)
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	seg[0][0]={INF, 0};
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}