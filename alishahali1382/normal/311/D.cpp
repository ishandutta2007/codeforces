#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int mod = 95542721;
const int MAXN = 100010, K=48;

int tav3(ll x){ return (x*x%mod)*x%mod;}

struct node{
	ll val[K];
	node(int x=0, int y=0){
		val[y]=x;
		for (int i=1; i<K; i++) val[(i+y)%K]=x=tav3(x);
	}
	node operator +(node x){
		node out;
		for (int i=0; i<K; i++) out.val[i]=(x.val[i]+val[i])%mod;
		return out;
	}
	node cyclic(int x){
		x%=K;
		node out(0);
		for (int i=0; i<K; i++) out.val[i]=val[(i+x)%K];
		return out;
	}
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, a, b, l, r;
ll A[MAXN];
int lazy[MAXN<<2];

void build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id]=node(A[tl]);
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid, tr);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

void add_lazy(int id, int lz){
	seg[id]=seg[id].cyclic(lz);
	lazy[id]=(lazy[id]+lz)%K;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, 1);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r);
	update(id<<1 | 1, mid, tr, l, r);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

ll get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id].val[0];
	shift(id);
	int mid=(tl+tr)>>1;
	return (get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid, tr, l, r))%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	build(1, 1, n+1);
	debug("built")
	cin>>m;
	while (m--){
		cin>>t>>l>>r;
		if (t==2) update(1, 1, n+1, l, r+1);
		else cout<<get(1, 1, n+1, l, r+1)%mod<<'\n';
	}
	
	return 0;
}
/*
5
6 5 4 2 8
6
2 1 4
2 1 3
2 1 1
2 1 5
1 1 3
2 1 2
*/