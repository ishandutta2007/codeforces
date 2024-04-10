#include<bits/stdc++.h>

const int N=100005;

int n,e[N][2],deg[N],a[N],ans[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[i][0]=x;e[i][1]=y;
		deg[x]++;deg[y]++;
	}
	int tot=0;
	for (int i=1;i<=n;i++) if (deg[i]==1) a[++tot]=i;
	if (tot==2)
	{
		for (int i=1;i<n;i++) printf("%d\n",i-1);
		return 0;
	}
	int now=3;
	for (int i=1;i<n;i++)
	{
		bool flag=0;
		for (int j=1;j<=3;j++)
			if (e[i][0]==a[j]||e[i][1]==a[j]) {ans[i]=j-1;flag=1;break;}
		if (!flag) ans[i]=now++;
	}
	for (int i=1;i<n;i++) printf("%d\n",ans[i]);
	return 0;
}