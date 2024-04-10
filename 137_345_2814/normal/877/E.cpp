#include<cstdio>
#include<algorithm>
using namespace std;
struct ed{
	int l,r,lazy,sm;
}e[800004];
int n,cnt,m,v[200001];
int head[200001],s[200001][2],dfc,kf[200001];
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	e[m].sm=e[m].lazy=0;
	if(l==r)
	{
		e[m].sm=kf[++cnt];
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	e[m].sm=e[m<<1].sm+e[m<<1|1].sm;
}
void push(int m)
{
	e[m<<1].sm=(e[m<<1].r-e[m<<1].l+1)-e[m<<1].sm;
	e[m<<1|1].sm=(e[m<<1|1].r-e[m<<1|1].l+1)-e[m<<1|1].sm;
	e[m<<1].lazy^=1;
	e[m<<1|1].lazy^=1;
	e[m].lazy=0;
}
void add(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	{
		e[m].sm=(e[m].r-e[m].l+1)-e[m].sm;
		e[m].lazy^=1;
		return;
	}
	if(e[m].lazy)
	push(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=r)
	add(m<<1,l,r);
	else
	if(l>mid)
	add(m<<1|1,l,r);
	else
	{
		add(m<<1,l,mid);
		add(m<<1|1,mid+1,r);
	}
	e[m].sm=e[m<<1].sm+e[m<<1|1].sm;
}
int ans;
void que(int m,int l,int r)
{
    if(l>r)
    return;
    if(e[m].l==l&&e[m].r==r)
    {
        ans+=e[m].sm;
        return;
    }
    int mid=(e[m].l+e[m].r)>>1;
    if(e[m].lazy)
    push(m);
    if(l>mid)
    que(m<<1|1,l,r);
    else
    if(r<=mid)
    que(m<<1,l,r);
    else
    {
        que(m<<1,l,mid);
        que(m<<1|1,mid+1,r);
    }
    return;
}
struct edge{
	int to,next;
}ed[200001];
void adde(int f,int t)
{
	ed[++cnt].to=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
}
void dfs(int n,int fa)
{
	s[n][0]=++dfc;
	kf[dfc]=v[n];
	for(int i=head[n];i;i=ed[i].next)
	if(ed[i].to!=fa)
	dfs(ed[i].to,n);
	s[n][1]=dfc;
}
int main()
{
	int a,b,c;
	char lsj[7];
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		adde(a,i);
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	cnt=0;
	dfs(1,0);
	build(1,1,n);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d",lsj,&b);
		if(lsj[0]=='p')
		add(1,s[b][0],s[b][1]);
		else
		{
			ans=0;
			que(1,s[b][0],s[b][1]);
			printf("%d\n",ans);
		}
	}
	return 0;
}