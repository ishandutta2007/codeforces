#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=1000005,E=262144;
#define inf 2147483647
int n,i,j,t,m,k,a[E],f[E],p[E];
long long ans;
int Find(int x)
{
	return (f[x]==-1?x:f[x]=Find(f[x]));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++p[a[i]];
		ans-=a[i];
	}
	++p[0];
	memset(f,-1,sizeof(f));
	for(i=E-1;i>=0;--i)
		for(j=i;j;j=(j-1)&i)
			if(p[j]&&p[i^j])
			{
				int x=Find(j),y=Find(i^j);
				if(x!=y)
				{
					f[x]=y;
					ans+=1ll*(p[j]+p[i^j]-1)*i;
					p[j]=p[i^j]=1;
				}
			}
	cout<<ans;
}