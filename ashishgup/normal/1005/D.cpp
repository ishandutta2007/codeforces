#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n;
string s;
int cache[N][3][2];

int dp(int i, int rem, int taken)
{
	if(i==n)
		return (rem==0 && taken==1);
	int &ans=cache[i][rem][taken];
	if(ans!=-1)
		return ans;
	if(!taken)
	{
		if(s[i]!='0')
			ans=max(dp(i+1, (rem+s[i]-'0')%3, 1), (((s[i]-'0')%3)==0) + dp(i+1, 0, 0));
		else
			ans=1+dp(i+1, 0, 0);
	}
	else
	{
		ans=max((((rem+s[i]-'0')%3)==0) + dp(i+1, 0, 0), dp(i+1, (rem+s[i]-'0')%3, 1));
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s;
	n=s.size();
	int ans=dp(0, 0, 0);
	cout<<ans;
	return 0;
}