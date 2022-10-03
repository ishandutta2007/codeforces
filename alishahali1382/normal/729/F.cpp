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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=4010, SQ=103;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], ps[MAXN];
int dp[MAXN][SQ*2][SQ];

int get(int l, int r, int k){
	assert(0<l+r-n+SQ && l+r-n+SQ<2*SQ);
	if (dp[l][l+r-n+SQ][k]<inf) return dp[l][l+r-n+SQ][k];
	if (r-l+1<k) return 0;
	if (r-l+1==k) return ps[r]-ps[l-1];
	int res=-inf;
	if (r-l+1<2*k) res=max(res, ps[l+k-1]-ps[l-1]);
	else if (r-l+1==2*k) res=max(res, ps[l+k-1]-ps[l-1] - (ps[r]-ps[r-k]));
	if (r-l+1>2*k){
		int tmp=min(get(l+k, r-k, k)-(ps[r]-ps[r-k]), get(l+k, r-k-1, k+1)-(ps[r]-ps[r-k-1]));
		res=max(res, ps[l+k-1]-ps[l-1] + tmp);
	}
	k++;
	if (r-l+1<2*k) res=max(res, ps[l+k-1]-ps[l-1]);
	else if (r-l+1==2*k) res=max(res, ps[l+k-1]-ps[l-1] - (ps[r]-ps[r-k]));
	if (r-l+1>2*k){
		int tmp=min(get(l+k, r-k, k)-(ps[r]-ps[r-k]), get(l+k, r-k-1, k+1)-(ps[r]-ps[r-k-1]));
		res=max(res, ps[l+k-1]-ps[l-1] + tmp);
	}
	k--;
	
	return dp[l][l+r-n+SQ][k]=res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], ps[i]=ps[i-1]+A[i];
	memset(dp, 63, sizeof(dp));
	cout<<get(1, n, 1)<<'\n';
	
	return 0;
}