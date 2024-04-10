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
const int MAXN=120010, LOG=20;

struct Node{
	int mn, ted;
	ll sum;
	Node(int a=0, int b=0, ll c=0){
		mn=a;
		ted=b;
		sum=c;
	}
};
Node Merge(Node X, Node Y){
	Node Z;
	Z.mn=min(X.mn, Y.mn);
	Z.sum=X.sum+Y.sum;
	Z.ted+=(Z.mn==X.mn)*X.ted;
	Z.ted+=(Z.mn==Y.mn)*Y.ted;
	return Z;
}

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], L[MAXN], R[MAXN];
Node seg[MAXN<<2];
int lazy1[MAXN<<2];
int lazy2[MAXN<<2];
ll ans[MAXN];
vector<pii> Q[MAXN];

void Build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id]=Node(tl, 1, 0);
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}
inline void add_lazy1(int id, int val){
	lazy1[id]+=val;
	seg[id].mn+=val;
}
inline void add_lazy2(int id, int val){
	lazy2[id]+=val;
	seg[id].sum+=seg[id].ted*val;
}
inline void shift(int id){
	if (lazy1[id]){
		add_lazy1(id<<1, lazy1[id]);
		add_lazy1(id<<1 | 1, lazy1[id]);
		lazy1[id]=0;
	}
	if (lazy2[id]){
		if (seg[id].mn==seg[id<<1].mn) add_lazy2(id<<1, lazy2[id]);
		if (seg[id].mn==seg[id<<1 | 1].mn) add_lazy2(id<<1 | 1, lazy2[id]);
		lazy2[id]=0;
	}
}
void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy1(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);	
}
ll Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id].sum;
	shift(id);
	int mid=(tl+tr)>>1;
	return Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r);
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		Q[y].pb({x, i});
	}
	Build(1, 1, n+1);
	for (int i=1; i<=n; i++){
		for (L[i]=i-1; L[i] && A[L[i]]>A[i]; ){
			int li=L[i], lli=L[L[i]];
			Add(1, 1, n+1, lli+1, li+1, A[li]-A[i]);
			L[i]=L[L[i]];
		}
		for (R[i]=i-1; R[i] && A[R[i]]<A[i]; ){
			int ri=R[i], rri=R[R[i]];
			Add(1, 1, n+1, rri+1, ri+1, A[i]-A[ri]);
			R[i]=R[R[i]];
		}
		add_lazy2(1, 1);
		for (pii p:Q[i]) ans[p.second]=Get(1, 1, n+1, p.first, i+1);
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<"\n";
	
	return 0;
}