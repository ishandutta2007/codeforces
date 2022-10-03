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
const int MAXN=500010, LOG=20;

ll ans; // :))
int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], last[MAXN], prv[MAXN];
pii seg[MAXN<<2];
int lazy[MAXN<<2];

pii combine(pii i, pii j){
	if (i.first<j.first) return i;
	if (i.first>j.first) return j;
	return {i.first, i.second+j.second};
}
inline void add_lazy(int id, int val){
	lazy[id]+=val;
	seg[id].first+=val;
}
inline void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}
pii Build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={0, 1};
	int mid=(tl+tr)>>1;
	return seg[id]=combine(Build(id<<1, tl, mid), Build(id<<1 | 1, mid, tr));
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
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}
pii Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return combine(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		prv[i]=last[A[i]];
		last[A[i]]=i;
	}
	seg[0]={inf, 0};
	Build(1, 1, n+1);
	int L=0;
	for (int i=1; i<=n; i++){
		Add(1, 1, n+1, prv[prv[prv[i]]]+1, prv[i]+1, -1);
		Add(1, 1, n+1, prv[prv[i]]+1, i+1, +1);
		L=max(L, prv[prv[prv[i]]]);
		ans+=combine({0, 0}, Get(1, 1, n+1, L+1, i)).second;
	}
	cout<<ans<<"\n";
	
	return 0;
}