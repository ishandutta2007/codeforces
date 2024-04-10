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
const int MAXN=500050;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
ll ps[MAXN];
int dp[MAXN];
map<int, int> last;

inline int cost(int l, int r){ // (l, r]
	if (A[l]<A[r]) return +(r-l);
	if (A[l]>A[r]) return -(r-l);
	return 0;
}

inline void upd(int l, int r){
	dp[r]=max(dp[r], dp[l]+cost(l, r));
}

struct Segment{
	int seg[MAXN<<1];
	void reset(){
		fill(seg, seg+2*m+5, -inf);
	}
	void Set(int pos, int val){
		pos+=m;
		for (seg[pos]=max(seg[pos], val); pos>1; pos>>=1) seg[pos>>1]=max(seg[pos], seg[pos^1]);
	}
	int Get(int l, int r){
		int res=seg[0];
		for (l+=m, r+=m; l<r; l>>=1, r>>=1){
			if (l&1) res=max(res, seg[l++]);
			if (r&1) res=max(res, seg[--r]);
		}
		return res;
	}
} seg1, seg2;

void Solve(){
	last.clear();
	vector<ll> comp={0};
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		ps[i]=ps[i-1]+A[i];
		comp.pb(ps[i]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=0; i<=n; i++) A[i]=lower_bound(all(comp), ps[i])-comp.begin();
	m=n+5;
//	for (int i=0; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	
	seg1.reset();
	seg2.reset();
	
	seg1.Set(A[0], 0);
	seg2.Set(A[0], 0);
	
	for (int i=1; i<=n; i++){
		dp[i]=dp[i-1]+cost(i-1, i);
		upd(last[A[i]], i);
		last[A[i]]=i;
		dp[i]=max(dp[i], seg1.Get(0, A[i])+i);
		dp[i]=max(dp[i], seg1.Get(A[i]+1, m)-i);
		
		seg1.Set(A[i], dp[i]-i);
		seg2.Set(A[i], dp[i]+i);
		
//		debug2(i, dp[i])
	}
	cout<<dp[n]<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
4
-7 6 -4 0

*/