#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1000005;
struct node
{
	int u,v,c,t,id;
}e[N];
int n,m,tag[N],p[N],cnt,d[N],c[N],i,j,k,head[N],adj[N],nxt[N],len[N],L,l,x,lt,rt,mid,col[N],q[N],bg,ed,tot,h[N],G[N],H[N];
bool v[N];
vector<int> vct[N],rvct[N],dzx[N];
bool cmp(node a,node b)
{
	return a.c<b.c;
}
void Addedge(int u,int v)
{
	G[++L]=u;
	H[L]=v;
	vct[u].push_back(v);
	rvct[v].push_back(u);
}
void Delete()
{
	vct[G[L]].erase(--vct[G[L]].end());
	rvct[H[L]].erase(--rvct[H[L]].end());
	--L;
}
void dfs(int x)
{
	v[x]=true;
	for(int y=vct[x].size()-1;y>=0;--y)
		if(!v[vct[x][y]])
			dfs(vct[x][y]);
	h[++cnt]=x;
}
void rdfs(int x)
{
	col[x]=cnt;
	dzx[cnt].push_back(x);
	for(int y=rvct[x].size()-1;y>=0;--y)
		if(!col[rvct[x][y]])
			rdfs(rvct[x][y]);
}
bool Judge()
{
	int i,j,k;
	cnt=0;
	for(i=1;i<=tot;++i)
		v[i]=false,col[i]=0;
	for(i=1;i<=tot;++i)
		if(!v[i])
			dfs(i);
	cnt=0;
	for(i=tot;i>=1;--i)
		if(!col[h[i]])
		{
			++cnt;
			dzx[cnt].clear();
			rdfs(h[i]);
		}
	for(i=1;i<=m;++i)
		if(col[2*i-1]==col[2*i])
			return false;
	for(i=1;i<=cnt;++i)
		d[i]=head[i]=0;
	l=0;
	for(i=1;i<=tot;++i)
		for(j=vct[i].size()-1;j>=0;--j)
			if(col[i]!=col[vct[i][j]])
			{
				adj[++l]=col[vct[i][j]];
				nxt[l]=head[col[i]];
				head[col[i]]=l;
				++d[adj[l]];
			}
	bg=1,ed=0;
	for(i=1;i<=cnt;++i)
		if(!d[i])
			q[++ed]=i;
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
	for(i=1;i<=cnt;++i)
		v[i]=false;
	for(i=cnt;i>=1;--i)
	{
		for(j=dzx[q[i]].size()-1;j>=0;--j)
			if(dzx[q[i]][j]<=2*m&&v[col[dzx[q[i]][j]+(dzx[q[i]][j]&1?1:-1)]])
				break;
		if(j<0)
			v[q[i]]=true;
	}
	for(i=1;i<=m;++i)
		if(!v[col[2*i-1]]&&!v[col[2*i]])
			return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].c,&e[i].t);
		e[i].id=i;
	}
	sort(e+1,e+1+m,cmp);
	for(i=1;i<=m;i=j)
	{
		cnt=0;
		l=0;
		for(j=i;j<=m&&e[i].c==e[j].c;++j)
		{
			++d[e[j].u],++d[e[j].v];
			if(tag[e[j].u]!=e[i].c)
			{
				tag[e[j].u]=e[i].c;
				p[++cnt]=e[j].u;
			}
			if(tag[e[j].v]!=e[i].c)
			{
				tag[e[j].v]=e[i].c;
				p[++cnt]=e[j].v;
			}
			adj[++l]=e[j].v;
			nxt[l]=head[e[j].u];
			head[e[j].u]=l;
			len[l]=j;
			adj[++l]=e[j].u;
			nxt[l]=head[e[j].v];
			head[e[j].v]=l;
			len[l]=j;
		}
		for(k=1;k<=cnt;++k)
			if(d[p[k]]>2)
			{
				printf("No");
				return 0;
			}
		for(k=i;k<j;++k)
		{
			for(x=head[e[k].u];x;x=nxt[x])
				if(len[x]!=k)
					Addedge(k*2,len[x]*2-1);
			for(x=head[e[k].v];x;x=nxt[x])
				if(len[x]!=k)
					Addedge(k*2,len[x]*2-1);
		}
		for(k=1;k<=cnt;++k)
			d[p[k]]=head[p[k]]=0;
	}
	l=0;
	for(j=1;j<=m;++j)
	{
		adj[++l]=e[j].v;
		nxt[l]=head[e[j].u];
		head[e[j].u]=l;
		len[l]=j;
		adj[++l]=e[j].u;
		nxt[l]=head[e[j].v];
		head[e[j].v]=l;
		len[l]=j;
	}
	tot=2*m;
	for(i=1;i<=n;++i)
	{
		cnt=0;
		for(j=head[i];j;j=nxt[j])
			p[++cnt]=len[j];
		for(j=1;j<=cnt;++j)
		{
			Addedge(tot+j,p[j]*2);
			Addedge(tot+cnt+j,p[j]*2);
			if(j>1)
			{
				Addedge(tot+j,tot+j-1);
				Addedge(p[j]*2-1,tot+j-1);
			}
			if(j<cnt)
			{
				Addedge(tot+cnt+j,tot+cnt+j+1);
				Addedge(p[j]*2-1,tot+cnt+j+1);
			}
		}
		tot+=2*cnt;
	}
	if(!Judge())
	{
		printf("No");
		return 0;
	}
	int Num=L;
	lt=0,rt=1000000000;
	while(lt<rt)
	{
		mid=(lt+rt)/2;
		while(L>Num)
			Delete();
		for(i=1;i<=m;++i)
			if(e[i].t>mid)
				Addedge(i*2-1,i*2);
		if(Judge())
			rt=mid;
		else
			lt=mid+1;
	}
	printf("Yes\n%d ",lt);
	while(L>Num)
		Delete();
	for(i=1;i<=m;++i)
		if(e[i].t>lt)
			Addedge(i*2-1,i*2);
	Judge();
	cnt=0;
	for(i=1;i<=m;++i)
		if(v[col[2*i-1]])
			p[++cnt]=i;
	printf("%d\n",cnt);
	for(i=1;i<=cnt;++i)
		printf("%d ",e[p[i]].id);
	return 0;
}