#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int m,n;
int a[N],b[N];
int f[N][2];
bool check (int xx)
{
	f[1][0] = f[1][1] = 0;
	for (int T=1;T<=2;T++)
	{
		//???????    ???????
		int pre0 = f[1][0], pre1 = f[1][1];
		memset(f,127,sizeof(f));
		f[1][0] = pre0; f[1][1] = pre1;
		for (int u=1;u<=n;u++)
		{
			if (f[u][0]<=0) f[u][1]=-xx-1;
			else if (f[u][0]<=xx) f[u][1]=min(f[u][1],-1);
			else return false;
			if (f[u][0]>0)
			{
				int len=a[u+1]-a[u]+f[u][0];
				if (len<=xx) f[u+1][1]=min(f[u+1][1],a[u+1]-a[u]-xx-1);
			}
			f[u+1][0]=a[u+1]-a[u]+f[u][1];
			//printf("%d %d %d\n",u,f[u][0],f[u][1]);
		}
		 if (f[n+1][0] <= pre0 && f[n+1][1] <= pre1) return 1;
        f[1][0] = f[n+1][0]; f[1][1] = f[n+1][1];
	}
	return false;
}
int main()
{
	scanf("%d%d",&m,&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	int mx=0,pos=1;
	for (int u=1;u<n;u++)
		if (mx<a[u+1]-a[u])	{mx=a[u+1]-a[u];pos=u;}
	if (a[1]-a[n]+m>mx)	{pos=n;mx=a[1]-a[n]+m;}
	for (int u=1;u<=n;u++)	{b[u]=a[pos];pos++;if (pos>n) pos=1;}
	for (int u=1;u<=n;u++) a[u]=b[u];a[n+1]=a[1];
	for (int u=2;u<=n+1;u++) if (a[u]<=a[u-1]) a[u]+=m;
	/*for (int u=1;u<=n+1;u++) printf("%d ",a[u]);
	printf("\n");*/
	//printf("%d\n",check(1));
	//printf("%d\n",mx);
	int l=0,r=mx,lalal=-1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid))	{r=mid-1;lalal=mid;}
		else l=mid+1;
	}
	printf("%d\n",lalal);
	return 0;
}