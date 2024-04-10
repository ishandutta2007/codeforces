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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=100010, LOG=18;

int n, m, q, k, d, u, v, x, y, t, a, b;
ll A[MAXN], B[MAXN], ans;
ll fen[MAXN];
ll seg[MAXN<<2], lazy[MAXN<<2];

void add(int pos, ll val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}
int Find(ll val){ // max(pos) : get(pos)<=val
	int pos=0;
	for (int i=LOG-1; ~i; i--) if (pos+(1<<i)<=m && fen[pos+(1<<i)]<=val) val-=fen[pos+=(1<<i)];
	return pos;
}
void Build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id]=B[tl];
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}
inline void add_lazy(int id, int len, ll val){
	lazy[id]+=val;
	seg[id]+=val*len;
}
inline void shift(int id, int tl, int tr){
	if (lazy[id]){
		int mid=(tl+tr)>>1;
		add_lazy(id<<1, mid-tl, lazy[id]);
		add_lazy(id<<1 | 1, tr-mid, lazy[id]);
		lazy[id]=0;
	}
}
void Add(int id, int tl, int tr, int l, int r, ll val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}
ll Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	n--;
	m--;
	for (int i=0; i<=n; i++) cin>>A[i];
	for (int i=0; i<=m; i++) cin>>B[i];
	ans=(n+m+1ll)*(A[0]+B[0]);
	for (int i=n; i; i--) A[i]-=A[i-1];
	for (int i=m; i; i--) B[i]-=B[i-1];
	// A and B sorted
	A[0]=B[0]=0;
	for (int i=1; i<=n; i++) ans+=A[i]*(n-i+1);
	for (int i=1; i<=m; i++) ans+=B[i]*(m-i+1);
	
	Build(1, 1, m+1);
	for (int i=1; i<=m; i++) add(i, +B[i]), add(i+1, -B[i]);
	
	while (q--){
		cin>>t>>k>>d;
		k=(t==1?n:m)-k+2;
		k--;
		if (!k) ans+=(n+m+1ll)*d, k++;
		if (t==1){
			ans+=(n-k+1ll)*(n-k+2ll)/2*d;
			for (int i=k; i<=n; i++) A[i]+=d;//, ans+=(n-i+1ll)*d;
		}
		if (t==2){
			ans+=(m-k+1ll)*(m-k+2ll)/2*d;
			
			Add(1, 1, m+1, k, m+1, d);
			add(k, +d);
//			for (int i=k; i<=m; i++) B[i]+=d;
		}
		ll res=0;
		for (int i=1; i<=n; i++){
			int pos=Find(A[i]);
			
//			if (pos<m) debug2(B[pos+1], A[i])
			res+=Get(1, 1, m+1, 1, pos+1);
			
			res+=max(0, m-pos)*A[i];

			
//			for (int j=1; j<=pos; j++) res+=min(A[i], B[j]);
			
//			for (int j=pos+1; j<=m; j++) res+=A[i]; //res+=min(A[i], B[j]);
//			for (int j=1; j<=m; j++) res+=min(A[i], B[j]);
			
		}
		cout<<ans+res<<"\n";
	}
	
	return 0;
}
/*
5 6 1
4 9 22 118 226
7 94 238 395 565 738
2 1 95




5 3 1
1 2 4 7 11
5 7 10
1 3 2



2 2 1
1 2
1 2
1 2 1

5 3 1
1 2 6 11 17
5 12 20
1 5 4

1 2 6 11 21
5 12 20

5 3 1
1 2 4 7 11
5 7 10
1 3 2

5 6 1
4 9 22 118 226
7 94 238 395 565 738
2 1 95


*/