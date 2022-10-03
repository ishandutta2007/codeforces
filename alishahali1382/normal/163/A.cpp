#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 5010;

int n, m, ans, tmp;
int dp[MAXN][MAXN];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>t;
	n=s.size();
	m=t.size();
	for (int i=1; i<=n; i++){
		tmp=0;
		for (int j=1; j<=m; j++){
			tmp=(tmp+dp[i-1][j-1])%mod;
			if (s[i-1]==t[j-1]) dp[i][j]=(tmp+1)%mod;
			ans=(ans+dp[i][j])%mod;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}