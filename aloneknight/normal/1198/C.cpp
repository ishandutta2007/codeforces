#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int t,n,m,k;bool c[N],d[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(d+1,0,n*3);
		scanf("%d%d",&n,&m);k=0;
		for(int i=1,u,v;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			if(!d[u]&&!d[v])d[u]=d[v]=c[i]=1,k++;else c[i]=0;
		}
		if(k>=n){puts("Matching");for(int i=1,j=1;j<=n;i++)if(c[i])printf("%d ",i),j++;}
		else {puts("IndSet");for(int i=1,j=1;j<=n;i++)if(!d[i])printf("%d ",i),j++;}
		puts("");
	}
	return 0;
}