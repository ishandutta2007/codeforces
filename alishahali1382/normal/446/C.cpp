#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000009;
const int MAXN = 300010, LOG=20;

ll n, m, k, u, v, x, y, t, l, r;
ll F[MAXN];
ll seg[MAXN<<2];
ll lazy1[MAXN<<2];
ll lazy2[MAXN<<2];

inline int md(int x){
	if (x>=mod) x-=mod;
	return x;
}

void build(int id, int tl, int tr){
	if (tr-tl==1){
		cin>>seg[id];
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid, tr);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
}

void add_lazy(int id, int len, ll lz1, ll lz2){
	lz1%=mod;
	lz2%=mod;
	lazy1[id]=md(lazy1[id]+lz1);
	lazy2[id]=md(lazy2[id]+lz2);
	seg[id]+=lz1*(F[len+2]-1);
	seg[id]+=lz2*(F[len+3]-2);
	seg[id]%=mod;
}

void shift(int id, int tl, int tr){
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy1[id], lazy2[id]);
	ll x=mid-tl;
	add_lazy(id<<1 | 1, tr-mid, lazy1[id]*F[x-1] + lazy2[id]*F[x], lazy1[id]*F[x] + lazy2[id]*F[x+1]);
	lazy1[id]=lazy2[id]=0;	
}

void update(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		if (l==tl) add_lazy(id, tr-tl, 1, 0);
		else add_lazy(id, tr-tl, F[tl-l-1], F[tl-l]);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r);
	update(id<<1 | 1, mid, tr, l, r);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
}

ll get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[1]=1;
	for (int i=2; i<MAXN; i++) F[i]=(F[i-1]+F[i-2])%mod;
	cin>>n>>m;
	build(1, 1, n+1);
	while (m--){
		cin>>t>>l>>r;
		if (t==1) update(1, 1, n+1, l, r+1);
		else cout<<get(1, 1, n+1, l, r+1)%mod<<'\n';
	}
		
	return 0;
}