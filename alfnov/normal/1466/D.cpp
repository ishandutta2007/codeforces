#include<bits/stdc++.h>
using namespace std;
int tt[100005],t2[100005],a[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)tt[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			tt[u]++,tt[v]++;
		}
		int tot=0;
		for(int i=1;i<=n;i++)for(int j=1;j<tt[i];j++)
			t2[++tot]=a[i];
		sort(t2+1,t2+tot+1,greater<int>());
		long long ans=0;
		for(int i=1;i<=n;i++)ans+=a[i];
		for(int i=1;i<n;i++)
		{
			printf("%lld",ans);
			if(i+1!=n)printf(" ");
			ans+=t2[i];
		}
		puts("");
	}
	return 0;
}