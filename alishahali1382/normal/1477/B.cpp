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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int f[MAXN], s[MAXN], L[MAXN], R[MAXN];
int seg[MAXN<<2], lazy[MAXN<<2];
string S;

void Build(int id, int tl, int tr){
	lazy[id]=-1;
	if (tr-tl==1){
		seg[id]=f[tl];
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
}
inline void add_lazy(int id, int len, int val){
	lazy[id]=val;
	seg[id]=len*val;
}
inline void shift(int id, int tl, int tr){
	if (lazy[id]==-1) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=-1;
}
void Set(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, l, r, val);
	Set(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}
int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r);
}
int Solve(){
	cin>>n>>m;
	for (int i=0; i<n; i++){
		char ch; cin>>ch;
		s[i]=ch-'0';
	}
	for (int i=0; i<n; i++){
		char ch; cin>>ch;
		f[i]=ch-'0';
	}
	for (int i=1; i<=m; i++) cin>>L[i]>>R[i];
	Build(1, 0, n);
	for (int i=m; i; i--){
		int l=L[i]-1, r=R[i], len=r-l;
		int t=Get(1, 0, n, l, r);
		if (2*t==len) kill("NO")
		if (2*t<len) Set(1, 0, n, l, r, 0);
		if (2*t>len) Set(1, 0, n, l, r, 1);
	}
	for (int i=0; i<n; i++) if (Get(1, 0, n, i, i+1)!=s[i]) kill("NO")
	kill("YES")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}