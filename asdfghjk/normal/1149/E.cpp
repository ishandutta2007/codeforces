#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int n,m,i,j,k,h[N],head[N],adj[N],nxt[N],sg[N],q[N],bg,ed,d[N],s[N];
bool v[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",h+i);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i]=k;
		nxt[i]=head[j];
		head[j]=i;
		++d[k];
	}
	for(i=1;i<=n;++i)
		if(!d[i])
			q[++ed]=i;
	bg=1;
	while(bg<=ed)
	{
		for(i=head[q[bg]];i;i=nxt[i])
		{
			--d[adj[i]];
			if(d[adj[i]]==0)
				q[++ed]=adj[i];
		}
		++bg;
	}
	for(i=n;i>=1;--i)
	{
		for(j=head[q[i]];j;j=nxt[j])
			v[sg[adj[j]]]=true;
		for(j=0;v[j];++j);
		sg[q[i]]=j;
		for(j=head[q[i]];j;j=nxt[j])
			v[sg[adj[j]]]=false;
	}
	for(i=1;i<=n;++i)
		s[sg[i]]^=h[i];
	for(i=n;i>=0;--i)
		if(s[i])
		{
			puts("WIN");
			for(j=1;j<=n;++j)
				if(sg[j]==i&&(s[i]^h[j])<=h[j])
				{
					h[j]=s[i]^h[j];
					for(k=0;k<=n;++k)
						v[k]=false;
					for(k=head[j];k;k=nxt[k])
						if(!v[sg[adj[k]]])
						{
							v[sg[adj[k]]]=true;
							h[adj[k]]=s[sg[adj[k]]]^h[adj[k]];
						}
					for(k=1;k<=n;++k)
						printf("%d ",h[k]);
					return 0;
				}
		}
	printf("LOSE");
	return 0;
}