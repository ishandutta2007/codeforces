#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
const int MAX=1e9+7;
int n,r;
struct qq
{
	int x,y,last;
}e[N*2];int num,last[N];
int a[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;
	e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int dep[N];
int L[N],R[N];
int mx=0;
void dfs (int x,int fa)
{
	L[x]=++num;mx=max(mx,dep[x]);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
	R[x]=num;
	//printf("%d %d %d\n",n,x,num);
}
int b[N];
bool cmp (int x,int y)	{return dep[x]<dep[y];}
int rt[N];
struct qr
{
	int c,s1,s2;
}tr[N*100];
void change (int &now,int l,int r,int x,int xx)
{
	num++;tr[num]=tr[now];now=num;
	tr[now].c=min(tr[now].c,xx);
	if (l==r) return ;
	int mid=(l+r)>>1;
	if (x<=mid) change(tr[now].s1,l,mid,x,xx);
	else change(tr[now].s2,mid+1,r,x,xx);
}
int calc (int now,int l,int r,int L,int R)
{
	if (now==0) return MAX;
	//printf("%d %d %d %d %d\n",l,r,tr[now].c,L,R);
	if (l==L&&r==R) return tr[now].c;
	int mid=(l+r)>>1;
	if (R<=mid) return calc(tr[now].s1,l,mid,L,R);
	else if (L>mid) return calc(tr[now].s2,mid+1,r,L,R);
	else return min(calc(tr[now].s1,l,mid,L,mid),calc(tr[now].s2,mid+1,r,mid+1,R));
}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//printf("%d\n",MAX);
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&r);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
//	printf("YES\n");
	num=0;dep[r]=1;dfs(r,0);
	for (int u=1;u<=n;u++) b[u]=u;
	sort(b+1,b+1+n,cmp);
	num=0;tr[0].c=MAX;
	//for (int u=1;u<=n;u++) printf("YES:%d %d\n",L[u],R[u]);
	for (int u=1;u<=n;u++)
	{
		//printf("NO:%d %d %d\n",b[u],dep[b[u]],L[b[u]]);
		if (dep[b[u]]!=dep[b[u-1]]) 
		{
		//	printf("OZY\n");
			rt[dep[b[u]]]=rt[dep[b[u-1]]];
		}
		change(rt[dep[b[u]]],1,n,L[b[u]],a[b[u]]);
		//printf("haha:%d\n",tr[rt[dep[b[u]]]].c);
	}
//	return 0;
	int m;
	scanf("%d",&m);
	int last=0;
	while (m--)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		x=(x+last)%n+1;
		k=(k+last)%n;
		//printf("YES:%d %d %d\n",min(mx,dep[x]+k),L[x],R[x]);
		last=calc(rt[min(mx,dep[x]+k)],1,n,L[x],R[x]);
		printf("%d\n",last);
	}
	return 0;
}