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
int A[MAXN], B[MAXN], L[MAXN];
ll seg[MAXN<<1], dp[MAXN];

void Set(int pos, ll val){
	for (seg[pos+=MAXN]=val; pos>1; pos>>=1) seg[pos>>1]=max(seg[pos], seg[pos^1]);
}
ll Get(int l, int r){
	ll res=seg[0];
	for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
		if (l&1) res=max(res, seg[l++]);
		if (r&1) res=max(res, seg[--r]);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i];
	memset(seg, -31, sizeof(seg));
	dp[0]=0;
	Set(0, 0);
	for (int i=1; i<=n; i++){
		for (L[i]=i-1; L[i] && A[L[i]]>=A[i]; L[i]=L[L[i]]);
		dp[i]=Get(L[i], i)+B[i];
		if (L[i]) dp[i]=max(dp[i], dp[L[i]]);
		Set(i, dp[i]);
	}
	cout<<dp[n]<<"\n";
	
	return 0;
}