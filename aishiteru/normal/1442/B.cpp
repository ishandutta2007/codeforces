#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=500005;
int n,i,j,t,a[N],s=1,id[N],b[N],vis[N],m;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			id[a[i]]=i;
			vis[i]=0;
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d",&b[i]);
			vis[id[b[i]]]=1;
		}
		vis[0]=vis[n+1]=1;
		s=1;
		for(i=1;i<=m;++i)
		{
			if(vis[id[b[i]]-1]&&vis[id[b[i]]+1])
				s=0;
			else
				if(!vis[id[b[i]]-1]&&!vis[id[b[i]]+1])
					s=s*2%M;
			vis[id[b[i]]]=0;
		}
		printf("%d\n",s);
	}
}