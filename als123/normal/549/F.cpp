#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=300005;
int n,k;
int a[N],s[N];
vector<int> d[1000005];
int l[N],r[N];
int find (int l,int r,int x)
{
	int lalal=upper_bound(d[x].begin(),d[x].end(),r)-d[x].begin()-1;
    int lalal1=lower_bound(d[x].begin(),d[x].end(),l)-d[x].begin()-1;
    return lalal-lalal1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);
		s[u]=(s[u-1]+a[u])%k;
	}
	for (int u=0;u<=n;u++) 
	{
		d[s[u]].push_back(u);
	}
	for (int u=1;u<=n;u++)	{l[u]=u-1;while (l[u]>=1&&a[l[u]]<a[u]) l[u]=l[l[u]];}
	for (int u=n;u>=1;u--)  {r[u]=u+1;while (r[u]<=n&&a[r[u]]<=a[u]) r[u]=r[r[u]];}
	long long ans=0;
	for (int u=1;u<=n;u++)
	{
		if (u-l[u]<r[u]-u)
		{
			for (int i=l[u]+1;i<=u;i++)// 
			{
				int lalal=(s[i-1]+a[u])%k;
				ans=ans+find(u,r[u]-1,lalal);
			}
		}
		else
		{
			for (int i=u;i<r[u];i++)
			{
				int lalal=((s[i]-a[u])%k+k)%k;	
				ans=ans+find(l[u],u-1,lalal);
			}
		}
	}
	printf("%lld\n",ans-n);
	return 0;
}