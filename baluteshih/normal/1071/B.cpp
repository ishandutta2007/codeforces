#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s[2000],ans;
bitset<2005> yes[2005];
int dp[2005][2005];

int main()
{jizz
	int n,k,x=0;
	char c;
	cin >> n >> k;
	for(int i=0;i<n;++i)
		cin >> s[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(s[i-1][j-1]=='a');
			if(i+j-1<=k+dp[i][j]) x=max(x,k+dp[i][j]);
		}
	if(x==0)
		yes[0][1]=yes[1][0]=1;
	else
	{
		x=min(x,2*n-1);
		for(int i=0;i<x;++i) ans.pb('a');
		for(int i=max(1,x+1-n);i<min(n+1,x+1);++i)
			if(dp[i][x+1-i]+k>=x) yes[i][x+1-i]=1;//,cout << i << " " << x+1-i << "\n";
	}
	for(int a=x+2;a<=n+n;++a)
	{
		c='z';
		for(int i=max(1,a-n);i<min(n+1,a);++i)
			if(yes[i-1][a-i]||yes[i][a-i-1]) 
				c=min(c,s[i-1][a-i-1]);
		ans.pb(c);
		for(int i=max(1,a-n);i<min(n+1,a);++i)
			if((yes[i-1][a-i]||yes[i][a-i-1])&&s[i-1][a-i-1]==c) 
				yes[i][a-i]=1;//,cout << i << " " << a-i << "\n";;
	}
	cout << ans << "\n";
}