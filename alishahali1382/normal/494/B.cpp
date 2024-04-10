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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, a, b, ans;
int kmp[2][MAXN];
int last[MAXN];
ll dp[MAXN], ps[MAXN];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>t;
	n=s.size();
	m=t.size();
	s="#"+s;
	t="#"+t;
	
	int k=0;
	for (int i=2; i<=m; i++){
		while (k && t[k+1]!=t[i]) k=kmp[0][k];
		kmp[0][i]=(k+=(t[k+1]==t[i]));
	}
	
	k=0;
	for (int i=1; i<=n; i++){
		while (k && t[k+1]!=s[i]) k=kmp[0][k];
		kmp[1][i]=(k+=(t[k+1]==s[i]));
	}
	
	//for (int i=1; i<=n; i++) cerr<<kmp[1][i]<<" \n"[i==n];
	
	for (int i=1; i<=n; i++){
		last[i]=last[i-1];
		if (kmp[1][i]==m) last[i]=i;
	}
	
	dp[0]=ps[0]=1;
	for (int i=1; i<=n; i++){
		dp[i]=dp[i-1];
		if (last[i]) dp[i]+=ps[last[i]-m];
		dp[i]%=mod;
		ps[i]=(ps[i-1]+dp[i])%mod;
		//debug2(i, dp[i])
	}
	cout<<(dp[n]-1+mod)%mod<<'\n';
	
	return 0;
}