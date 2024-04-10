#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long sum[100004];
struct node{
	int l,r,sz;
	long long sum;
}e[400003];
struct que{
	int a,b;
}ed[100003];
bool cmp(que a,que b)
{
	return a.a<b.a;
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	if(l==r)
	return;
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
}
void add(int m,int x)
{
	if(e[m].l==e[m].r&&e[m].l==x)
	{
		e[m].sz+=1;
		e[m].sum+=x;
		return;
	}
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=x)
	add(m<<1,x);
	else
	add(m<<1|1,x);
	e[m].sz=e[m<<1].sz+e[m<<1|1].sz;
	e[m].sum=e[m<<1].sum+e[m<<1|1].sum;
}
long long query(int m,int x)
{
	if(e[m].l==e[m].r)
	return e[m].l*x;
	if(e[m<<1].sz>=x)
	return query(m<<1,x);
	else
	return e[m<<1].sum+query(m<<1|1,x-e[m<<1].sz);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&ed[i].a);
	for(int i=1;i<=n;i++)
	scanf("%d",&ed[i].b);
	sort(ed+1,ed+n+1,cmp);
	for(int i=n;i>=1;i--)
	sum[i]=sum[i+1]+ed[i].b;
	long long ans=1e18;
	build(1,1,100000);
	int nt=1;
	while(nt<=n)
	{
		int st=nt;
		while(ed[nt].a==ed[nt+1].a) nt++;
		long long tmp=sum[nt+1];
		int tmp2=st-1-(nt-st);
		if(tmp2>0)
		{
			long long tmp3=query(1,tmp2);
			tmp+=tmp3;
		}
		ans=min(ans,tmp);
		for(int i=st;i<=nt;i++)
		add(1,ed[i].b);
		nt++;
	}
	printf("%lld\n",ans);
}