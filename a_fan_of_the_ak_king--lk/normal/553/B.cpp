#include<bits/stdc++.h>
using namespace std;
int n,i,ans[55];
long long k;
long long f[55];
int main()
{
	cin>>n>>k;
	f[1]=1;
	for(i=2;i<=n;++i)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>k)
			f[i]=k+1;
	}
	for(i=1;i<=n;++i)
		if(k>f[n-i+1])
		{
			ans[i]=i+1;
			ans[i+1]=i;
			k-=f[n-i+1];
			++i;
		}
		else
			ans[i]=i;
	for(i=1;i<=n;++i)
		cout<<ans[i]<<' ';
}