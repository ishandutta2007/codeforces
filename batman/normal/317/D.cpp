#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)32*1000)
#define K ((ll)30)

ll n,ans=1,dp[K]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	ll cnt=max(0ll,n-N+1);
	for(int i=2;i<N;i++)
		if(!mark[i])
		{
			ll p=0;
			for(ll j=i;j<=n;j*=i,p++)
			{
				if(j<N)mark[j]=1;
				else cnt--;
			}
			ans^=dp[p];
		}
	if(cnt%2)ans^=1;
	cout<<(ans?"Vasya":"Petya");
	return 0;
}