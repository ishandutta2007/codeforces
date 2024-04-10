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
const int MAXN=1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN], P[MAXN];
int seg[MAXN<<2], lazy[MAXN<<2];
int fen[MAXN];

void add_lazy(int id, int val){
	seg[id]+=val;
	lazy[id]+=val;
}
void shift(int id){
	if (lazy[id]){
		add_lazy(id<<1, lazy[id]);
		add_lazy(id<<1 | 1, lazy[id]);
		lazy[id]=0;
	}
}
void Build(int id, int tl, int tr){
	lazy[id]=0;
	if (tr-tl==1){
		seg[id]=0;
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
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
void add(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}
ll CountInv(){
	ll res=0;
	for (int i=1; i<=n; i++){
		add(P[i], +1);
		res+=i-get(P[i]);
	}
	for (int i=1; i<=n; i++) add(P[i], -1);
	return res;
}
void Main(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], P[i]=i;
	for (int i=1; i<=m; i++) cin>>B[i];
	sort(P+1, P+n+1, [](int i, int j){ return pii(A[i], i)<pii(A[j], j);});
	sort(B+1, B+m+1);
	ll ans=CountInv();
//	debug(ans)
	Build(1, 1, n+1);
	for (int i=1; i<=n; i++) Add(1, 1, n+1, 1, i+1, -1);
	int j=1, kirekhar=0;
	for (int i=1; i<=m; i++){
		if (B[i]==B[i-1]){
			ans+=kirekhar;
			continue ;
		}
		while (j<=n && B[i]>A[P[j]]) Add(1, 1, n+1, 1, P[j++]+1, +2);
		int jj=j;
		while (jj<=n && B[i]==A[P[jj]]) Add(1, 1, n+1, 1, P[jj++]+1, +1);
		if (jj==n+1) break ;
		kirekhar=(n+1-jj) + min(seg[1], 0);
		ans+=kirekhar;
		while (j<jj) Add(1, 1, n+1, 1, P[j++]+1, +1);
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	Main();
//	return 0;
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*

1
5 2
71 3 50 7 30
7 7

*/