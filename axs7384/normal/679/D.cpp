#include<bits/stdc++.h>
using namespace std;
const int N=405;
int a[N][N],n,m,x,y,u,v,q[N];
double sum,ans,t,s,b[N],c[N];
int main()
{
	memset(a,0x3f,sizeof(a));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		a[i][i]=0;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for (int i=1;i<=n;++i)
	{
		sum=0;
		for (int j=0;j<n;++j)
		{
			u=0;
			memset(b,0,sizeof(b));
			for (int k=1;k<=n;++k)
				if (a[i][k]==j)
				{
					++u;
					v=0;
					for (int l=1;l<=n;++l)
						if (a[k][l]==1)
							++v;
					for (int l=1;l<=n;++l)
						if (a[k][l]==1)
							b[l]+=1.0/v;
				}
			q[0]=0;
			for (int k=1;k<=n;++k)
				if (abs(a[i][k]-j)<=1)
					q[++q[0]]=k;
			t=0;
			for (int k=1;k<=n;++k)
			{
				s=0;
				for (int l=1;l<=q[0];l++)
					if (b[q[l]]>c[a[k][q[l]]])
						c[a[k][q[l]]]=b[q[l]];
				for (int l=1;l<=q[0];l++)
				{	
					s+=c[a[k][q[l]]];
					c[a[k][q[l]]]=0;
				}
				t=max(t,s);
			}
			if (u)
				t=max(t,1.0);
			//printf("%d %d %.12lf\n",i,j,sum);
			sum+=t/n;
		}
		ans=max(ans,sum);
	}
	printf("%.12lf",ans);
}