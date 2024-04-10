#include<bits/stdc++.h>
using namespace std;
int n,q,sq;
int a[100002],bl[100002],laz[322],st[322],ed[322],infa[100002],outfa[100002];
bool ok[322];
inline int A(int x)
{
	return max(a[x]-laz[bl[x]],0);
}
inline void init(int x)
{
	if(ok[x])return ;
	for(int i=st[x];i<=ed[x];++i)infa[i]=(A(i)<st[x]? i:infa[A(i)]),outfa[i]=(A(i)<st[x]? A(i):outfa[A(i)]);
	for(int i=st[x];i<=ed[x];++i)if(A(i)>=st[x])return ;
	ok[x]=1,laz[x]=0;
}
int main()
{
	scanf("%d%d",&n,&q),sq=sqrt(n);
	for(int i=2;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)bl[i]=(i-1)/sq+1;
	for(int i=1;i<=bl[n];++i)st[i]=(i-1)*sq+1,ed[i]=min(i*sq,n),init(i);
	for(int o,x,y,z;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			scanf("%d",&z);
			if(bl[x]==bl[y])
			{
				for(int i=x;i<=y;++i)a[i]=max(a[i]-z,0),outfa[i]=max(outfa[i]-z,0);
				init(bl[x]);
				continue;
			}
			for(int i=x;i<=ed[bl[x]];++i)a[i]=max(a[i]-z,0),outfa[i]=max(outfa[i]-z,0);
			init(bl[x]);
			for(int i=bl[x]+1;i<bl[y];++i)laz[i]=min(laz[i]+z,n),init(i);
			for(int i=st[bl[y]];i<=y;++i)a[i]=max(a[i]-z,0),outfa[i]=max(outfa[i]-z,0);
			init(bl[y]);
		}
		else
		{
			for(;bl[x]!=bl[y] || infa[x]!=infa[y];x=max(outfa[x]-(ok[bl[x]]? laz[bl[x]]:0),0))if(bl[x]<bl[y])swap(x,y);
			for(;x!=y;x=A(x))if(x<y)swap(x,y);
			printf("%d\n",max(x,1));
		}
	}
	return 0;
}