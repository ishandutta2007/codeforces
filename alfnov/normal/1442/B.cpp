#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],hs[200005],vist[200005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)hs[i]=vist[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),hs[a[i]]=i;
		for(int i=1;i<=m;i++)scanf("%d",&b[i]),vist[hs[b[i]]]=1;
		vist[0]=vist[n+1]=1;
		int ans=1;
		for(int i=1;i<=m;i++)
		{
			int tt=hs[b[i]];
			if(vist[tt-1]&&vist[tt+1])
			{
				ans=0;
				break;
			}
			if(!vist[tt-1]&&!vist[tt+1])ans=2*ans%998244353;
			vist[tt]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}