#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,t,x,a[N],i,s,u,v,j,f[N];
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)
				f[i]=i+1;
			else
				f[i]=0;
		}
		f[n+1]=0;
		long long ans=0;
		for(i=1;i<=n;++i)
		{
			if(a[i]>=n)
			{
				ans+=a[i]-n;
				a[i]=n;
			}
				while(a[i]>1)
				{
					++ans;
					j=i;
					while(j<=n)
					{
						if(a[j]==1)
						{
							j=Find(j);
							continue;
						}
						int t=j;
						j+=a[j];
						if(a[t]==2)
							f[t]=Find(t+1);
						a[t]=max(a[t]-1,1);
					}
					//for(j=1;j<=n;++j)
					//	cout<<a[j]<<' ';
					//cout<<endl;
					//cout<<a[i]<<' '<<j<<endl;
				}
		}
		cout<<ans<<endl;
	}
}