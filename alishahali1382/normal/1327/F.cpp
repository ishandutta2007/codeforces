#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int mod = 998244353;
const int MAXN = 500010;

ll n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
piii B[MAXN];
ll dp[MAXN];
int shit[MAXN];

ll Solve(int bit){
	memset(shit, 0, sizeof(shit));
	memset(A, 0, sizeof(A));
	memset(dp, 0, sizeof(dp));
	
	for (int i=1; i<=m; i++){
		int l=B[i].first.first, r=B[i].first.second, x=((B[i].second>>bit)&1);
		if (x==1){
			A[l]++;
			A[r+1]--;
			continue ;
		}
		else shit[r]=max(shit[r], l);
	}
	for (int i=1; i<=n; i++) A[i]+=A[i-1];
	
	int curr=0;
	dp[0]=1;
	ll sum=1;
	for (int i=1; i<=n; i++){
		if (!A[i]){
			dp[i]=sum;
			//debug(i)
		}
		while (curr<shit[i]){
			sum-=dp[curr];
			sum%=mod;
			curr++;
		}
		sum+=dp[i];
		sum%=mod;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>m;
	for (int i=1; i<=m; i++) cin>>B[i].first.first>>B[i].first.second>>B[i].second;
	
	ll ans=1;
	for (int i=0; i<k; i++) ans=ans*Solve(i)%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	/*
	debug(Solve(0))
	debug(Solve(1))
	debug(Solve(2))
	*/
	return 0;
}