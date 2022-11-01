#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,a[N],cnt,dp[N];
ll par[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n==0)return cout<<"ab\n",0;
	for(ll i=2;;i++)
	{
		ll ex=i*(i-1)/2;
		if(ex>N)break;
		a[cnt++]=ex;
	}
	dp[0]=0;
	//ll maxi=0;
	for(int i=1;i<N;i++)
	{
		dp[i]=N;
		for(int j=0;j<cnt && a[j]<=i;j++)
			if(dp[i]>dp[i-a[j]]+1)
				dp[i]=dp[i-a[j]]+1,par[i]=j;
	//	maxi=max(maxi,dp[i]);
	}
	//cout<<maxi<<"\n";
	ll now=0;
	while(n)
	{
		for(int i=0;i<(par[n]+2);i++)
			cout<<(char)(now+'a');
		n-=a[par[n]];
		now++;
	}
	cout<<"\n";
	return 0;
}