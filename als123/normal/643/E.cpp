#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=500005;
int n;
double f[N][45];
int fa[N];
int tot[N];
double Pow[N];
int main()
{
	Pow[0]=1;	for (int u=1;u<=500000;u++) Pow[u]=Pow[u-1]*0.5;
	n=1;
	for (int u=0;u<=40;u++) f[1][u]=1;
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if (op==1)
		{
			n++;fa[n]=x;tot[x]++;
			for (int u=0;u<=40;u++) f[n][u]=1;
			double last=f[x][0];
			f[x][0]=Pow[tot[x]];
			//printf("%lf\n",f[x][0]);
			for (int u=1;u<=40;u++)
			{
				if (x==1) break;
				int ff=fa[x];
				double Last=f[ff][u];
				f[ff][u]=f[ff][u]/(0.5+0.5*last);
				f[ff][u]=f[ff][u]*(0.5+0.5*f[x][u-1]);
				last=Last;x=ff;
			}
		}
		else
		{
			double ans=0;
			for (int u=1;u<=40;u++) ans=ans+u*(f[x][u]-f[x][u-1]);
			printf("%.6lf\n",ans);
		}
	}
	return 0;
}