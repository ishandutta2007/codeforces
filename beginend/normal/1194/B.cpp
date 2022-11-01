#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

const int N=50005;

int n,m,s1[N],s2[N];
std::vector<int> a[N];
char str[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<std::max(n,m);i++) s1[i]=s2[i]=0,a[i].clear();
		for (int i=0;i<n;i++)
		{
			scanf("%s",str);
			for (int j=0;j<m;j++)
				if (str[j]=='.') s1[i]++,s2[j]++,a[i].pb(0);
				else a[i].pb(1);
		}
		int ans=n*m;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (a[i][j]==0) ans=std::min(ans,s1[i]+s2[j]-1);
				else ans=std::min(ans,s1[i]+s2[j]);
		printf("%d\n",ans);
	}
	return 0;
}