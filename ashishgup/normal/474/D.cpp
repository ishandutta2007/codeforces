#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
const int MOD=1e9+7;

int t, k;
int cache[N];

int dp(int i)
{
	if(i<=0)
	    return i==0;
	if(cache[i]!=-1)
		return cache[i];	
	cache[i]=dp(i-1)+dp(i-k);
	if(cache[i]>=MOD)
	{
	    cache[i]-=MOD*(cache[i]/MOD);
	}
	return cache[i];
}

int main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>t>>k;
	cache[0]=0;
	dp(100000);
	for(int i=1;i<=1e5;i++)
	{
		cache[i]+=cache[i-1];
		if(cache[i]>=MOD)
		{
			cache[i]-=MOD*(cache[i]/MOD);
		}
	}
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int ans=cache[b]-cache[a-1]+MOD;
		if(ans>=MOD)
		{
			ans-=MOD*(ans/MOD);
		}
		cout<<ans<<endl;
	}
	return 0;
}