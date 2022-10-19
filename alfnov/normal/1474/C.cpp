#include<bits/stdc++.h>
using namespace std;
int a[2005],b[2005],vist[2005],q1[2005],q2[2005];
vector<int>g[1000005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		n=2*n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
		{
			memset(vist,0,sizeof(vist));
			vist[i]=vist[n]=1;
			int tb=a[n],ff=1,gs=0,tot=0;
			for(int j=1;j<=n;j++)g[a[j]].clear();
			for(int j=1;j<=n;j++)if(j!=i&&j!=n)g[a[j]].push_back(j);
			for(int j=n-1;j>=1;j--)if(!vist[j])
			{
				g[a[j]].pop_back();
				if(!g[tb-a[j]].size())
				{
					ff=0;
					break;
				}
				int tt=g[tb-a[j]][g[tb-a[j]].size()-1];
				g[tb-a[j]].pop_back();
				vist[j]=vist[tt]=1;
				gs+=2;
				q1[++tot]=j,q2[tot]=tt;
				tb=a[j];
			}
			if(!ff||gs!=n-2)continue;
			flag=1;
			puts("YES");
			cout<<a[i]+a[n]<<endl<<a[i]<<" "<<a[n]<<endl;
			for(int j=1;j<=tot;j++)printf("%d %d\n",a[q1[j]],a[q2[j]]);
			break;
		}
		if(!flag)puts("NO");
		for(int i=1;i<=n;i++)g[a[i]].clear();
	}
	return 0;
}