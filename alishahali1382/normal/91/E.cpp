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
const int MAXN=100010, LOG=18;

int n, m, k, u, v, x, y, t, l, r, ans;
pii A[MAXN];
int sz[MAXN<<2];
pii seg[LOG][MAXN];

inline int Inter(int i, int j){
	pii a=A[i], b=A[j];
	if (a.first==b.first) return (a.second<=b.second?-inf:inf);
	return ceil((b.second-a.second+.0)/(a.first-b.first));// + ((b.second-a.second)%(a.first-b.first)>0);
}
inline void Add(pii *B, int &sz, int i){
	while (sz && Inter(B[sz-1].second, i)<=B[sz-1].first) sz--;
	if (!sz) B[sz++]={-inf, i};
	else B[sz]={Inter(B[sz-1].second, i), i}, sz++;
}
inline pll Get(pii *B, int sz, int x){
	int i=(upper_bound(B, B+sz, pii(x, inf))-1)->second;
	return {1ll*A[i].first*x + A[i].second, i};
}
void Build(int h, int id, int tl, int tr){
	if (tr-tl==1){
		Add(seg[h]+tl, sz[id], tl);
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(h+1, id<<1, tl, mid);
	Build(h+1, id<<1 | 1, mid, tr);
	merge(seg[h+1]+tl, seg[h+1]+tl+sz[id<<1], seg[h+1]+mid, seg[h+1]+mid+sz[id<<1 | 1], seg[h]+tl, [](pii x, pii y){
		return A[x.second]<A[y.second];
	});
	for (int i=0; i<sz[id<<1]+sz[id<<1 | 1]; i++) Add(seg[h]+tl, sz[id], seg[h][tl+i].second);
}
pll Get(int h, int id, int tl, int tr, int l, int r, int x){
	if (r<=tl || tr<=l) return {-inf, -1};
	if (l<=tl && tr<=r) return Get(seg[h]+tl, sz[id], x);
	int mid=(tl+tr)>>1;
	return max(Get(h+1, id<<1, tl, mid, l, r, x), Get(h+1, id<<1 | 1, mid, tr, l, r, x));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i].second>>A[i].first;
	Build(0, 1, 1, n+1);
	while (m--){
		cin>>l>>r>>t;
		cout<<Get(0, 1, 1, n+1, l, r+1, t).second<<"\n";
	}
	
	return 0;
}
/*
3 1
10 2
2 7
9 100
1 3 0

*/