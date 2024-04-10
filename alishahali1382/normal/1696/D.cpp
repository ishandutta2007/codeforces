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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];

struct Segment{
	pii seg[MAXN<<1];
	inline void Reset(){
		seg[0]={-inf, -1};
		fill(seg+1, seg+2*n+1, seg[0]);
	}
	inline void Set(int pos, int val){
		seg[pos+n]={val, pos};
		for (pos+=n; pos>1; pos>>=1) seg[pos>>1]=max(seg[pos], seg[pos^1]);
	}
	inline int Get(int l, int r){
		pii res=seg[0];
		for (l+=n, r+=n; l<r; l>>=1, r>>=1){
			if (l&1) res=max(res, seg[l++]);
			if (r&1) res=max(res, seg[--r]);
		}
		return res.second;
	}
} segmn, segmx;

int Solve(int x, int y){
	if (x==y) return 0;
	int mn=segmn.Get(x, y+1);
	int mx=segmx.Get(x, y+1);
	if (mx==x){
		if (mn==y) return 1;
		return Solve(x, mn) + Solve(mn, y);
	}
	if (mx==y){
		if (mn==x) return 1;
		return Solve(x, mn) + Solve(mn, y);
	}
	return Solve(x, mx) + Solve(mx, y);
}

int Main(){
	cin>>n;
	segmn.Reset();
	segmx.Reset();
	for (int i=1; i<=n; i++){
		cin>>A[i];
		segmn.Set(i, -A[i]);
		segmx.Set(i, +A[i]);
	}
	cout<<Solve(1, n)<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}