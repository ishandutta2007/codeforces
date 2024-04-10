#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)105)
#define SQ ((ll)600*1000)
#define INF ((ll)2e9)

ll n,k,a[N],sum,ans,maxi;
//int arr[10*SQ],cnt;

ll calc(ll x)
{
	ll res=0;
	for(int i=0;i<n;i++)
		res+=((a[i]+x-1)/x)*x-a[i];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i],sum+=a[i],maxi=max(maxi,a[i]);
	if(maxi*n-sum<=k)return cout<<maxi+(k-(maxi*n-sum))/n,0;
	for(int i=1;i<=SQ;i++)
		if(calc(i)<=k)
			ans=max(ans,(ll)i);
	
	/*for(int i=0;i<n;i++)
		for(ll j=1;;j++)
		{
			if(a[i]/j<=SQ)break;
			arr[cnt++]=(a[i]+j-1)/j-1;
		}
	sort(arr,arr+cnt);cnt=unique(arr,arr+cnt)-arr;*/
	for(int j=n+1;j<=SQ;j++)
	{
		ll ex=(sum+k)/j;
		if(!ex)break;
	//	if(ex>arr[i])continue;
		if(calc(ex)<=k)
			ans=max(ans,(ll)ex);
	}
		
	cout<<ans;
	return 0;
}