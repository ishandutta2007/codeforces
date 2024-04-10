#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
const int MAX=(1<<28);
int n,q;
struct qq
{
	int x,y,last;
}e[N];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int tot[N],son[N],fa[N],top[N];
void dfs (int x)
{
	tot[x]=1;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		fa[y]=x;dfs(y);
		tot[x]=tot[x]+tot[y];
		if (tot[y]>tot[son[x]])	son[x]=y;
	}
}
int L[N],R[N],ys[N];
void dfs1 (int x,int tp)
{
	top[x]=tp;ys[x]=++num;L[x]=num;
	if (son[x]!=0) dfs1(son[x],tp);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa[x]||y==son[x]) continue;
		dfs1(y,y);
	}
	R[x]=num;
}
struct qw	{int c,c1;};
struct qr
{
	int l,r;
	int s1,s2;
	qw c;
	bool lzy;//-1 
}tr[N*2];int Num;
void bt (int l,int r)
{
	int a=++Num;
	tr[a].l=l;tr[a].r=r;
	tr[a].c.c=-(r-l+1);
	tr[a].c.c1=-1;
	tr[a].lzy=false;
	if (l==r) return ;
	int mid=(l+r)>>1;
	tr[a].s1=Num+1;bt(l,mid);
	tr[a].s2=Num+1;bt(mid+1,r);
}
//
qw update(qw x,qw y)
{
	qw ans;
	ans.c=x.c+y.c;
	ans.c1=max(y.c1,y.c+x.c1);
	return ans;
}
void up (int now,int x)
{
	tr[now].c.c=(tr[now].r-tr[now].l+1)*x;
	tr[now].c.c1=x;
	if (x==-1) tr[now].lzy=true;
}
void Push_down (int now)
{
	if (tr[now].lzy==false) return ;
	tr[now].lzy=false;
	int s1=tr[now].s1,s2=tr[now].s2;
	up(s1,-1);up(s2,-1);
}
void add (int now,int x,int xx)
{
	if (tr[now].l==tr[now].r)	{tr[now].c.c+=xx;tr[now].c.c1+=xx;return ;}
	Push_down(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (x<=mid) add(s1,x,xx);
	else add(s2,x,xx);
	tr[now].c=update(tr[s1].c,tr[s2].c);
}
qw find_ans (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)	return tr[now].c;
	Push_down(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) return find_ans(s1,l,r);
	else if (l>mid) return find_ans(s2,l,r);
	else return update(find_ans(s1,l,mid),find_ans(s2,mid+1,r));
}
int calc (int x)
{
	int tp=top[x];
	qw ans,k;
	ans.c=0;ans.c1=-MAX;
	while (tp!=1)
	{
		k=find_ans(1,ys[tp],ys[x]);
		ans=update(k,ans);
		x=fa[tp];tp=top[x];
		//printf("YES:%d %d %d %d\n",k.c,k.c1,ans.c,ans.c1);
	}
	k=find_ans(1,ys[1],ys[x]);
	ans=update(k,ans);
	//printf("YES:%d %d %d %d\n",k.c,k.c1,ans.c,ans.c1);
	return ans.c1;
}
void change (int now,int l,int r,int x)
{
	//if (tr[now].l==tr[now].r)	{tr[now].c.c=x;tr[now].c.c1=x;return ;}
	if (tr[now].l==l&&tr[now].r==r)
	{
		up(now,x);
		return ;
	}
	Push_down(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) change(s1,l,r,x);
	else if (l>mid) change(s2,l,r,x);
	else change(s1,l,mid,x),change(s2,mid+1,r,x);
	tr[now].c=update(tr[s1].c,tr[s2].c);
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&q);
	for (int u=2;u<=n;u++)
	{
		int x,y;
		scanf("%d",&x);
		init(x,u);
	}
	dfs(1);
	num=0;dfs1(1,1);
	Num=0;bt(1,num);
	while (q--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if (op==1)	add(1,ys[x],1);
		if (op==2)
		{
			change(1,L[x],R[x],-1);
			int t=calc(x);
			if (t>=0) 
			{
				//printf("YES:%d\n",t);
				add(1,L[x],-(t+1));
				//change(1,L[x],L[x],-(t+1));
				//printf("OZY:%d\n",calc(x));
			}
		}
		if (op==3)
		{
			int t=calc(x);
			if (t>=0) printf("black\n");
			else printf("white\n");
		}
	}
	return 0;
}