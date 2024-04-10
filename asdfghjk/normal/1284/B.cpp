#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
struct node
{
	int l,r;
}p[N];
int n,m,a[N],i,j,k,l,x,ok,tot,w[N];
long long ans;
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&m);
		for(j=1,k=1<<30,l=-1,x=0;j<=m;++j)
		{
			scanf("%d",a+j);
			if(k<a[j])
				x=1;
			k=min(k,a[j]);
			l=max(l,a[j]);
		}
		if(x)
			++ok;
		else
		{
			p[++tot]=(node){k,l};
			w[tot]=l;
		}
	}
	ans=1ll*n*n;
	sort(p+1,p+1+tot,cmp);
	sort(w+1,w+1+tot);
	for(i=1;i<=tot;++i)
	{
		j=upper_bound(w+1,w+1+tot,p[i].l)-w-1;
		ans-=j;
	}
	printf("%lld",ans);
	return 0;
}