#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int N=400005;
struct node
{
	long double st,ed;
	int l,r;
}tk[N];
bool operator <(node a,node b)
{
	return a.ed>b.ed;
}
struct mode
{
	long double st,ed;
	int l,r;
};
priority_queue<node> q;
vector<node> vct[N];
int n,m,t,c,v,u,cnt,head[N],adj[N*2],nxt[N*2],size[N],dep[N],fa[N],son[N],tp[N],i,j,k,tot;
long double ans=1e50,Tm[2*N];
bool operator <(mode a,mode b)
{
	if(fabs(a.l+(a.r-a.l)/(a.ed-a.st)*(Tm[j]-a.st)-b.l-(b.r-b.l)/(b.ed-b.st)*(Tm[j]-b.st))>1e-8)
		return a.l+(a.r-a.l)/(a.ed-a.st)*(Tm[j]-a.st)<b.l+(b.r-b.l)/(b.ed-b.st)*(Tm[j]-b.st);
	if(a.l!=b.l)
		return a.l<b.l;
	if(a.r!=b.r)
		return a.r<b.r;
	if(fabs(a.st-b.st)>1e-8)
		return a.st<b.st;
	return a.ed<b.ed;
}
multiset<mode> st;
multiset<mode>::iterator ddq,dzx;
bool cmp(node a,node b)
{
	return a.st<b.st;
}
void dfs(int x,int dad)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+1;
			fa[adj[y]]=x;
			dfs(adj[y],x);
			size[x]+=size[adj[y]];
			if(!son[x]||size[adj[y]]>size[son[x]])
				son[x]=adj[y];
		}
}
void Dfs(int x,int dad)
{
	if(son[x])
	{
		tp[son[x]]=tp[x];
		Dfs(son[x],x);
	}
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad&&adj[y]!=son[x])
		{
			tp[adj[y]]=adj[y];
			Dfs(adj[y],x);
		}
}
void work(int id,long double st,long double ed,int l,int r)
{
	vct[id].push_back((node){st,ed,l,r});
}
void phh(mode a,mode b)
{
	if(max(a.l,a.r)<min(b.l,b.r)||max(b.l,b.r)<min(a.l,a.r)||a.ed<b.st||b.ed<a.st)
		return;
	if(a.l==a.r&&b.l==b.r)
	{
		if(a.l==b.l&&fabs(a.st-b.st)<1e-8)
			ans=min(ans,a.st);
		return;
	}
	if(a.l==a.r)
		swap(a,b);
	if(b.l==b.r)
	{
		if(min(a.l,a.r)<=b.l&&max(a.l,a.r)>=b.l&&a.st<=b.st&&a.ed>=b.st&&fabs(a.st+(b.l-a.l)/((a.r-a.l)/(a.ed-a.st))-b.st)<1e-6)
			ans=min(ans,b.st);
		return;
	}
	long double A=(a.ed-a.st)/(a.r-a.l)-(b.ed-b.st)/(b.r-b.l),B=b.st-a.st+a.l*(a.ed-a.st)/(a.r-a.l)-b.l*(b.ed-b.st)/(b.r-b.l);
	if(fabs(A)<1e-8)
	{
		if(fabs(B)<1e-8)
			ans=min(ans,max(a.st,b.st));
		return;
	}
	long double x=a.st+(B/A-a.l)/((a.r-a.l)/(a.ed-a.st));
	if(x>=a.st&&x<=a.ed&&x>=b.st&&x<=b.ed)
		ans=min(ans,x);
}
void Insert(mode g)
{
	//printf("+%lf %lf %d %d\n",g.st,g.ed,g.l,g.r);
	ddq=st.upper_bound(g);
	if(ddq!=st.end())
		phh(g,*ddq);
	if(ddq!=st.begin())
	{
		ddq--;
		phh(g,*ddq);
	}
	st.insert(g);
}
void Erase(mode g)
{
	//printf("-%lf %lf %d %d\n",g.st,g.ed,g.l,g.r);
	st.erase(st.find(g));
	ddq=st.upper_bound(g);
	if(ddq!=st.end()&&ddq!=st.begin())
	{
		dzx=ddq;
		dzx--;
		phh(*dzx,*ddq);
	}
}
int lca(int a,int b)
{
	while(tp[a]!=tp[b])
	{
		if(dep[tp[a]]<dep[tp[b]])
			swap(a,b);
		a=fa[tp[a]];
	}
	return dep[a]<dep[b]?a:b;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	dfs(1,-1);
	tp[1]=1;
	Dfs(1,-1);
	while(m--)
	{
		scanf("%d%d%d%d",&t,&c,&v,&u);
		i=0,j=dep[v]+dep[u]-2*dep[lca(v,u)];
		while(tp[v]!=tp[u])
		{
			if(dep[tp[v]]>dep[tp[u]])
			{
				work(tp[v],1.0*i/c+t,1.0*(i+dep[v]-dep[fa[tp[v]]])/c+t,dep[v],dep[fa[tp[v]]]);
				i+=dep[v]-dep[fa[tp[v]]];
				v=fa[tp[v]];
			}
			else
			{
				work(tp[u],1.0*(j-(dep[u]-dep[fa[tp[u]]]))/c+t,1.0*j/c+t,dep[fa[tp[u]]],dep[u]);
				j-=dep[u]-dep[fa[tp[u]]];
				u=fa[tp[u]];
			}
		}
		if(dep[v]>dep[u])
			work(tp[v],1.0*i/c+t,1.0*(i+dep[v]-dep[u])/c+t,dep[v],dep[u]);
		else
			work(tp[u],1.0*(j-(dep[u]-dep[v]))/c+t,1.0*j/c+t,dep[v],dep[u]);
	}
	for(i=1;i<=n;++i)
		if(!vct[i].empty())
		{
			sort(vct[i].begin(),vct[i].end(),cmp);
			while(!q.empty())
				q.pop();
			st.clear();
			cnt=0;
			for(j=0;j<vct[i].size();++j)
				Tm[++cnt]=vct[i][j].st,Tm[++cnt]=vct[i][j].ed;
			sort(Tm+1,Tm+1+cnt);
			for(j=1,k=0;j<=cnt&&ans-Tm[j]>1e-8;++j)
			{
				while(k<vct[i].size()&&vct[i][k].st<=Tm[j])
				{
					q.push(vct[i][k]);
					Insert((mode){vct[i][k].st,vct[i][k].ed,vct[i][k].l,vct[i][k].r});
					++k;
				}
				while(!q.empty()&&q.top().ed<=Tm[j])
				{
					Erase((mode){q.top().st,q.top().ed,q.top().l,q.top().r});
					q.pop();
				}
			}
		}
	if(ans>1e20)
		printf("-1");
	else
		printf("%.10lf",(double)ans);
	return 0;
}