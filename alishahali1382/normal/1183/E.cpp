#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 110, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
string s;
ll dp[MAXN][26];
ll val[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>s;
	for (int i=0; i<n; i++){
		int c=s[i]-'a';
		for (int len=n; len>1; len--){
			dp[len][c]=0;
			for (int cc=0; cc<26; cc++) dp[len][c]+=dp[len-1][cc];
			dp[len][c]=min(dp[len][c], k+1);
		}
		dp[1][c]=1;
	}
	
	val[0]=1;
	for (int i=1; i<=n; i++){
		for (int j=0; j<26; j++) val[i]+=dp[i][j];
		val[i]=min(val[i], k);
	}
	
	
	
	for (int len=n; len>=0; len--) if (k){
		ll tmp=min(k, val[len]);
		k-=tmp;
		ans+=tmp*(n-len);
	}
	if (k) kill(-1)
	cout<<ans<<'\n';
	
	return 0;
}