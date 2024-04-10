#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e9+7;

int n;
int cache[105][256];
string s;

int dp(int i, char ch)
{
	if(i==n)
		return 1;
	int &ans=cache[i][ch];
	if(ans!=-1)
		return ans;
	if(s[i]!='?')
	{
		if(s[i]==ch)
			ans=0;
		else
			ans=dp(i+1, s[i]);
	}
	else
	{
		ans=0;
		if(ch!='C')
			ans+=dp(i+1, 'C');
		if(ch!='Y')
			ans+=dp(i+1, 'Y');
		if(ch!='M')
			ans+=dp(i+1, 'M');
	}
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>s;
	int ans=dp(0, '*');
	if(ans>=2)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}