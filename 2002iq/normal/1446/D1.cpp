#include <bits/stdc++.h>
using namespace std;
#define MX 200000
int a[MX+5],cnt[105],cur[105],l[105][2*MX+5];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	pair<int,int> f(0,0);
	memset(l,-1,sizeof(l));
	for (int i=1;i<=100;i++)
	{
		f=max(f,make_pair(cnt[i],i));
		l[i][MX]=0;
	}
	for (int i=1;i<=n;i++)
	{
		cur[a[i]]++;
		if (a[i]==f.second)
		{
			for (int j=1;j<=100;j++)
			cur[j]--;
		}
		for (int j=1;j<=100;j++)
		{
			if (j!=f.second)
			{
				if (l[j][cur[j]+MX]==-1)
				l[j][cur[j]+MX]=i;
				ans=max(ans,i-l[j][cur[j]+MX]);
			}
		}
	}
	printf("%d",ans);
}