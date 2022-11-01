#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,a[N],dp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ll res;
		if(i==0)res=20;
		else res=20+dp[i-1];
		ll it=(lower_bound(a,a+i,a[i]-1440+1)-a)-1;
		if(it==-1)res=min(res,(ll)120);
		else res=min(res,dp[it]+120);
		it=(lower_bound(a,a+i,a[i]-90+1)-a)-1;
		if(it==-1)res=min(res,(ll)50);
		else res=min(res,dp[it]+50);
		dp[i]=res;
		cout<<dp[i]-dp[i-1]<<"\n";
	}
	return 0;
}