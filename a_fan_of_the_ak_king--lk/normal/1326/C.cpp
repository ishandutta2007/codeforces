#include<bits/stdc++.h>
using namespace std;
const int N=200005,E=262144;
const int M=998244353;
int n,t,i,a[N],b[N],vis[N],las,k;
long long s,ans=1;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[a[i]]=i;
	}
	for(i=n;i>n-k;--i)
	{
		s+=i;
		vis[b[i]]=1;
	}
	for(i=1;i<=n;++i)
		if(vis[i]==1)
		{
			if(las)
				ans=ans*(i-las)%M;
				las=i;
		}
	cout<<s<<' '<<ans;
}