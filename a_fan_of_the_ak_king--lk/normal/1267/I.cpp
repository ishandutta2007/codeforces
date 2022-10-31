#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int t,n,i,j,a[1005],k,u[1005],p[1005],q[1005],mp,mq,vis[105],g[105],o;
char c[15];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		srand(time(0));
		for(i=1;i<=n*2;++i)
			a[i]=i;
		mp=mq=0;
		for(i=1;i<n*2;i+=2)
		{
			printf("? %d %d\n",i,i+1);
			fflush(stdout);
			scanf("%s",c);
			if(c[0]=='>')
			{
				p[++mp]=i;
				q[++mq]=i+1;
			}
			else
			{
				p[++mp]=i+1;
				q[++mq]=i;
			}
		}
		memset(vis,0,sizeof(vis));
		for(i=1;i<=mq;++i)
			for(j=i+1;j<=mq;++j)
			{
				printf("? %d %d\n",q[i],q[j]);
				fflush(stdout);
				scanf("%s",c);
				if(c[0]=='>')
					vis[j]=1;
				else
					vis[i]=1;
			}
		for(i=1;i<=mq;++i)
			if(!vis[i])
				break;
		int tmp=i;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=mp;++i)
			for(j=i+1;j<=mq;++j)
				if(i!=tmp&&j!=tmp)
				{
					printf("? %d %d\n",p[i],p[j]);
					fflush(stdout);
					scanf("%s",c);
					if(c[0]=='>')
						vis[j]=1;
					else
						vis[i]=1;
				}
		for(i=1;i<=n;++i)
			if(i!=tmp&&!vis[i])
				break;
		int t2=i;
		o=0;
		for(i=1;i<=n;++i)
			if(i!=tmp&&i!=t2)
				g[++o]=p[i];
		for(i=1;i<=n;++i)
			g[++o]=q[i];
		for(i=1;i<=o;++i)
			for(j=i+1;j<=o;++j)
			{
				printf("? %d %d\n",g[i],g[j]);
				fflush(stdout);
				scanf("%s",c);
			}
		printf("!\n");
		fflush(stdout);
	}
}