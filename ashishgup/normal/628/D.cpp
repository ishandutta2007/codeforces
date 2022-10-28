#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;
const int MOD=1e9+7;

int m, d;
int cache[N][N][3][2];
string a, b;
int x[N];

int dp(int idx, int rem, int cur, int less)
{
	if(idx==2001)
		return (rem==0);
	int &ans=cache[idx][rem][cur][less];
	if(ans!=-1)
		return ans;
	ans=0;
	int lim=(less)?9:x[idx];
	if(cur==2)
	{
		ans=dp(idx+1, rem, cur, less|(0<x[idx]));
		for(int i=1;i<=lim;i++)
		{
			if(i==d)
				continue;
			ans+=dp(idx+1, (rem*10 + i)%m, 0, less|(i<x[idx]));
		}

	}
	else if(cur==1)
	{
		for(int i=0;i<=lim;i++)
		{
			if(i==d)
				continue;
			ans+=dp(idx+1, (rem*10 + i)%m, 0, less|(i<x[idx]));
		}
	}
	else
	{
		if(d<=lim)
			ans=dp(idx+1, (rem*10 + d)%m, 1, less|(d<x[idx]));
	}
	ans%=MOD;
	return ans;
}

int f(string &s)
{
	memset(cache, -1, sizeof(cache));
	memset(x, 0, sizeof(x));
	int idx=s.size()-1, xidx=2000;
	while(idx>=0)
		x[xidx--]=s[idx--]-'0';
	int ans=dp(0, 0, 2, 0);
	return ans;
}

int check(string &s)
{
	for(int i=1;i<s.size();i+=2)
		if(s[i]-'0'!=d)
			return 0;
	for(int i=0;i<s.size();i+=2)
		if(s[i]-'0'==d)
			return 0;
	int sum=0;
	for(int i=0;i<s.size();i++)
		sum=(sum*10 + s[i]-'0')%m;
	return (sum==0);
}

int32_t main()
{
	IOS;
	cin>>m>>d;
	cin>>a>>b;
	int ans=f(b) - f(a) + MOD;
	ans%=MOD;
	ans+=check(a);
	cout<<ans;
	return 0;
}