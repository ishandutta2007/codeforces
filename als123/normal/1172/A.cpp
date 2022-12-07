#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int a[N],b[N],n;
bool vis[N];
int f[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++) scanf("%d",&b[u]);
	for (int u=1;u<=n;u++)	if (b[u]==1)
	{
		bool tf=true;
        for (int i=u+1;i<=n;i++)	if(i-u+1!=b[i]) tf=false;
        for (int i=1;i<=n;i++) vis[a[i]]=true;
        int now=n-u+1;
        for (int i=1;i<u;i++)
        {
        	if (vis[now+i]==false) tf=false;
        	vis[b[i]]=true;
		}
		if (tf)
		{
			printf("%d\n",u-1);
			return 0;
		}
	}
	for (int u=1;u<=n;u++) f[a[u]]=0;
	for (int u=1;u<=n;u++) f[b[u]]=u;
	int ans=0;
	for (int u=1;u<=n;u++) ans=max(ans,n-u+1+f[u]);
	printf("%d\n",ans);
	return 0;
}