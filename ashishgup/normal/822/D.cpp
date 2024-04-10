//ACed in Gym

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5e6+1;
const int MOD=1e9+7;

int t, l, r;
long long f[N];

int32_t main()
{
	IOS;
	cin>>t>>l>>r;
	for(int i=1;i<N;i++)
	{
		f[i]=1LL*i*(i-1)/2;
	}
	for(int i=2;i<N;i++)
	{
		for(int j=2;i*j<N;j++)
		{
			f[i*j]=min(f[i*j], j*f[i] + f[j]);
		}
	}
	long long ans=0;
	int cur=1;
	for(int i=l;i<=r;i++)
	{
		ans+=(cur*(f[i]%MOD))%MOD;
		cur=(1LL*cur*t)%MOD;
	}
	ans%=MOD;
	cout<<ans;
 	return 0;
}