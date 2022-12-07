#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int N=100005;
const int MAX=(1<<28);
int n;
struct qq
{
	int x,y,z,last;
}e[N*2];int num,last[N];
void init (int x,int y,int z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
int tot[N];
int tmp,tmp1,root;
int g[N];// 
void get_root (int x,int fa)
{
	tot[x]=1;
	int mx=0;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		get_root(y,x);
		tot[x]=tot[x]+tot[y];
		mx=max(mx,tot[y]);
	}
	mx=max(mx,n-tot[x]);
	if (mx<tmp1)	{tmp1=mx;tmp=x;}
}
LL dep[N];
int L[N],R[N];
int bel[N];
void dfs (int x,int fa)
{
	L[x]=++num;bel[num]=x;tot[x]=1;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dep[y]=dep[x]+e[u].z;
		dfs(y,x);	
		tot[x]=tot[x]+tot[y];
	}
	R[x]=num;
}
int Ans[N];
struct qt
{
	int l,r;
	int s1,s2;
	int c;// 
}tr[N*2];
void update (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c=min(tr[s1].c,tr[s2].c);
}
void bt (int l,int r)
{
	int a=++num;
	tr[a].l=l;tr[a].r=r;
	if (l==r)	{tr[a].c=bel[l];return ;}
	int mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
	update(a);
}
int c;
void get (int now,int l,int r)
{
	if (l>r) return ;
	//printf("OK:%d %d %d %d %d\n",tr[now].l,tr[now].r,l,r,tr[now].c);
	if (tr[now].l==l&&tr[now].r==r)
	{
		c=min(c,tr[now].c);
		return ;
	}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) get(s1,l,r);
	else if (l>mid) get(s2,l,r);
	else get(s1,l,mid),get(s2,mid+1,r);
}
void Del (int now,int x)
{
	if (tr[now].l==tr[now].r)	{tr[now].c=MAX;return ;}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) Del(s1,x);
	else Del(s2,x);
	update(now);
}
int sum[N];//t+x    i+
set<pair<int,int> > s;
set<pair<int,int> > :: iterator it;
void dfs1 (int x,int rt,int fa)
{
	g[x]=rt;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dfs1(y,rt,x);
	}
}
void del (int x)
{
	if (x!=root)
	{
		int xx=g[x];
		it=s.lower_bound(make_pair(sum[xx],xx));
		s.erase(it);
		sum[xx]--;
		s.insert(make_pair(sum[xx],xx));
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	if (n==1)	{printf("0\n1\n");return 0;}
	for (int u=1;u<n;u++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		init(x,y,z);init(y,x,z);
	}
	tmp1=n+1;get_root(1,0);
	root=tmp;
	num=0;dfs(root,0);
	/*for (int u=1;u<=n;u++)
		printf("L:%d R:%d\n",L[u],R[u]);*/
	/*printf("%d\n",root);
	for (int u=1;u<=n;u++) printf("%d ",tot[u]);
	printf("\n");*/
	/*for (int u=1;u<=n;u++) printf("%d ",bel[u]);
	printf("\n");*/
	num=0;bt(1,n);
	LL ans=0;
	for (int u=1;u<=n;u++)	ans=ans+dep[u];
	printf("%lld\n",ans*2);
	for (int u=last[root];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		sum[y]=tot[y]+tot[y];
		dfs1(y,y,root);
		s.insert(make_pair(sum[y],y));
		//printf("YES:%d %d %d\n",root,y,sum[y]);
	}
	//printf("YES:%d\n",root);
	/*printf("g:");
	for (int u=1;u<=n;u++) printf("%d ",g[u]);
	printf("\n");*/
	int ff=-1;
	for (int u=1;u<=n;u++)
	{
		int lst=n-(u-1);
		if (ff==-1)
		{
			it=s.lower_bound(make_pair(lst,0));
			if (it!=s.end())	ff=(*it).second;
		}
		c=MAX;
		int xx=g[u];
		if (ff==-1)// 
		{
			if (u==root)// 
			{
				get(1,1,n);
			}
			else// 
			{
				get(1,1,L[xx]-1);
				get(1,R[xx]+1,n);
			}
		}
		else// 
		{
			if (xx==ff)// 
			{
				//printf("L:%d R:%d\n",L[u],R[u]);
				get(1,1,L[xx]-1);
				//printf("l:%d r:%d\n",1,L[u]-1);
				get(1,R[xx]+1,n);	
				//printf("l:%d r:%d\n",R[u]+1,n);
			}
			else
			{
				//printf("YES:%d %d\n",L[ff],R[ff]);
				get(1,L[ff],R[ff]);
			}
		}
		//c1 
		printf("%d ",c);
		del(u);
		if (u!=c) del(c);
		Del(1,L[c]);
	}
	return 0;
}