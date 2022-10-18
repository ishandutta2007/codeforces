#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=1e9+7;
ll dp[3][200005];

int main()
{jizz
	ll n,l,r,cnt[3]={0,0,0};
	cin >> n >> l >> r;
	dp[0][0]=1;
	cnt[0]=(r-l+1)/3;
	cnt[1]=(r-l+1)/3;
	cnt[2]=(r-l+1)/3;
	if((r-l+1)%3==1)
		++cnt[l%3];
	else if((r-l+1)%3==2)
		++cnt[l%3],++cnt[(l+1)%3];
	for(int i=1;i<=n;++i)
	{
		dp[0][i]=(dp[0][i-1]*cnt[0]+dp[1][i-1]*cnt[2]+dp[2][i-1]*cnt[1])%MOD;
		dp[1][i]=(dp[0][i-1]*cnt[1]+dp[1][i-1]*cnt[0]+dp[2][i-1]*cnt[2])%MOD;
		dp[2][i]=(dp[0][i-1]*cnt[2]+dp[1][i-1]*cnt[1]+dp[2][i-1]*cnt[0])%MOD;
	}
	cout << dp[0][n] << "\n";
}