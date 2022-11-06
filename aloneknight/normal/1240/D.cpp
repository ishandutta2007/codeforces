#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int n,cc,x,a[N],fa[N];
map<int,int>nxt[N];
ll ans,sum[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);cc=x=ans=0;sum[x]=1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(x&&nxt[fa[x]][a[i]]==x)x=fa[x];
			else if(nxt[x][a[i]])x=nxt[x][a[i]];
			else nxt[x][a[i]]=++cc,fa[cc]=x,x=cc;
			ans+=sum[x]++;
		}
		printf("%lld\n",ans);
		for(int i=0;i<=cc;i++)sum[i]=fa[i]=0,nxt[i].clear();
	}
	return 0;
}