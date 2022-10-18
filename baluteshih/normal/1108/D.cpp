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

int dp[3][200005],num[256];
string s,ch="RGB";

int main()
{jizz
	int n,nw,ru;
	cin >> n >> s,num['R']=0,num['G']=1,num['B']=2;
	dp[num[s.back()]][n-1]=0,dp[(num[s.back()]+1)%3][n-1]=dp[(num[s.back()]+2)%3][n-1]=1;
	for(int i=n-2;i>=0;--i)
	{
		dp[num[s[i]]][i]=min(dp[(num[s[i]]+1)%3][i+1],dp[(num[s[i]]+2)%3][i+1]);
		dp[(num[s[i]]+1)%3][i]=min(dp[num[s[i]]][i+1],dp[(num[s[i]]+2)%3][i+1])+1;
		dp[(num[s[i]]+2)%3][i]=min(dp[num[s[i]]][i+1],dp[(num[s[i]]+1)%3][i+1])+1;
	}
	ru=0;
	if(dp[0][0]<dp[1][0]&&dp[0][0]<dp[2][0]) nw=0;
	else if(dp[1][0]<dp[2][0]) nw=1;
	else nw=2;
	--n;
	cout << dp[nw][0] << "\n";
	for(;ru<n;++ru)
	{
		cout << ch[nw];
		if(s[ru]==ch[nw])
			if(dp[nw][ru]==dp[(nw+1)%3][ru+1]) nw=(nw+1)%3;
			else nw=(nw+2)%3; 
		else
			if(dp[nw][ru]==dp[(nw+1)%3][ru+1]+1) nw=(nw+1)%3;
			else nw=(nw+2)%3;
	}
	cout << ch[nw] << "\n"; 
}