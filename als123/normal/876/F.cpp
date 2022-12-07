#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n;
LL a[N];
LL L[N],R[N];
LL l[N],r[N]; 
LL sta[N],top;
LL vis[35];// 
void prepare ()
{
	LL top=0;
    for (LL u=1;u<=n;u++)
    {
        while (top!=0&&a[sta[top]]<a[u]) R[sta[top--]]=u-1;
        L[u]=sta[top]+1;sta[++top]=u;
    }
    while (top!=0) R[sta[top--]]=n;
    memset(vis,0,sizeof(vis));
    for (LL u=1;u<=n;u++)
    {
    	LL x=a[u];
    	for (LL i=1;i<=34;i++)// 
    	{
    		LL o=(x&1);
    		if (o==0)//0
    			l[u]=max(l[u],vis[i]);
    		else
    			vis[i]=u;
    		x>>=1;
		}
	}
	for (LL u=1;u<=34;u++) vis[u]=n+1;
	for (LL u=n;u>=1;u--)
	{
		r[u]=n+1;
		LL x=a[u];
    	for (LL i=1;i<=34;i++)// 
    	{
    		LL o=(x&1);
    		if (o==0)//0
    		{
    			r[u]=min(r[u],vis[i]);
    		}
    		else
    			vis[i]=u;
    		x>>=1;
		}
	}
}
void solve ()
{
	LL ans=0;
	for (LL u=1;u<=n;u++)// 
	{
		if (L[u]<=l[u])
		{
			if (R[u]>=r[u])
				ans=ans+(u-L[u]+1)*(R[u]-u+1)-(r[u]-u)*(u-l[u]);
			else ans=ans+(l[u]-L[u]+1)*(R[u]-u+1);
		}
		else	if (R[u]>=r[u])
			ans=ans+(R[u]-r[u]+1)*(u-L[u]+1);
	}
	printf("%I64d\n",ans);
}
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)	scanf("%I64d",&a[u]);
	prepare();
	solve();
	return 0;
}