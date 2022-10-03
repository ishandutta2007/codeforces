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
const int MAXN=100010, SZ=17*17*MAXN;

int n, m, k, u, v, x, y, t, a, b;
int L[MAXN], R[MAXN], root[MAXN], ans[MAXN];
int lc[SZ], rc[SZ], seg[SZ], ts;
vector<int> vec[MAXN];

int Add1(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return id;
	int res=++ts;
	seg[res]=min(seg[id], val);
	if (tr-tl>1){
		int mid=(tl+tr)>>1;
		lc[res]=Add1(lc[id], tl, mid, pos, val);
		rc[res]=Add1(rc[id], mid, tr, pos, val);
	}
	return res;
}
int Get1(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l || !id) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return min(Get1(lc[id], tl, mid, l, r), Get1(rc[id], mid, tr, l, r));
}
void Add2(int x, int y, int val){
	for (; x<=n+1; x+=x&-x) root[x]=Add1(root[x], 1, n+1, y, val);
}
int Get2(int x, int y){
	int res=seg[0];
	for (; x; x-=x&-x) res=min(res, Get1(root[x], 1, n+1, y, n+1));
	return res;
}

int Solve(int l, int r){
	if (r-l<=0) return 0;
	int id=Get2(r, l);
//	cerr<<l<<" "<<r<<"  "<<id<<"\n";
	if (!id || id>m) return 0;
	return R[id]-L[id] + Solve(l, L[id]) + Solve(R[id], r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>L[i]>>R[i];
		R[i]++;
		vec[R[i]-L[i]].pb(i);
	}
	seg[0]=inf;
	
	for (int i=n; i; i--){
		for (int j:vec[i]) Add2(R[j], L[j], j);
		ans[i]=Solve(1, n+1);
//		debug2(i, ans[i])
	}
	for (int i=1; i<=n; i++) cout<<ans[i]<<"\n";
	
	return 0;
}