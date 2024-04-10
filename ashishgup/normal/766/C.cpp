#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e3+5;
const int MOD=1e9+7;

int n;
int a[N];
int cache[N], cache2[N], cache3[N];

string s;

int dp1(int i)
{
	if(i==n)
		return 1;
	int &ans=cache[i];
	if(ans!=-1)
		return ans;
	ans=0;
	int maxlen=n;
	for(int j=i;j<n;j++)
	{
		maxlen=min(maxlen, a[s[j]-'a']);
		if(j-i+1>maxlen)
			break;
		ans+=dp1(j+1);
		ans%=MOD;
	}
	return ans;
}

int dp2(int i)
{
	if(i==n)
		return 0;
	int &ans=cache2[i];
	if(ans!=-1)
		return ans;
	ans=0;
	int maxlen=n;
	for(int j=i;j<n;j++)
	{
		maxlen=min(maxlen, a[s[j]-'a']);
		if(j-i+1>maxlen)
			break;
		ans=max(ans, max(j-i+1, dp2(j+1)));
	}
	return ans;
}

int dp3(int i)
{
	if(i==n)
		return 0;
	int &ans=cache3[i];
	if(ans!=-1)
		return ans;
	ans=n;
	int maxlen=n;
	for(int j=i;j<n;j++)
	{
		maxlen=min(maxlen, a[s[j]-'a']);
		if(j-i+1>maxlen)
			break;
		ans=min(ans, 1+dp3(j+1));
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	memset(cache3, -1, sizeof(cache3));
	cin>>n>>s;
	for(int i=0;i<26;i++)
		cin>>a[i];
	int ans1=dp1(0);
	int ans2=dp2(0);
	int ans3=dp3(0);
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	cout<<ans3<<endl;
	return 0;
}