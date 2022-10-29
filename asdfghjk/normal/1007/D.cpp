#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=300005;
int n,m,i,j,k,l,L,tot,stk[N*30],top,hhead[N],aadj[N*2],nnxt[N*2],Head[N*30],Adj[N*30],Nxt[N*30],head[N*30],adj[N*30],nxt[N*30],rhead[N*30],radj[N*30],rnxt[N*30],q[N*30],bg,ed,d[N*30],w[N*30],col[N*30],num,dep[N],fa[N],tp[N],id[N],h[N*30],size[N],son[N];
bool v[N*30];
vector<int> vct[N*5],Vct[N*30];
int Tag;
void addedge(int u,int v)
{
	//printf("%d %d\n",u,v);
	adj[++l]=v;
	nxt[l]=head[u];
	head[u]=l;
	radj[l]=u;
	rnxt[l]=rhead[v];
	rhead[v]=l;
}
void predfs(int x,int dad)
{
	size[x]=1;
	for(int y=hhead[x];y;y=nnxt[y])
		if(aadj[y]!=dad)
		{
			dep[aadj[y]]=dep[x]+1;
			fa[aadj[y]]=x;
			predfs(aadj[y],x);
			size[x]+=size[aadj[y]];
			if(!son[x]||size[aadj[y]]>size[son[x]])
				son[x]=aadj[y];
		}
}
void preDfs(int x,int dad)
{
	id[x]=++i;
	if(son[x])
	{
		tp[son[x]]=tp[x];
		preDfs(son[x],x);
	}
	for(int y=hhead[x];y;y=nnxt[y])
		if(aadj[y]!=dad&&aadj[y]!=son[x])
		{
			tp[aadj[y]]=aadj[y];
			preDfs(aadj[y],x);
		}
}
void update(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		vct[o].push_back(z);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
}
void work(int o,int l,int r)
{
	int Top=top;
	for(int i=vct[o].size()-1;i>=0;--i)
	{
		++tot;
		addedge(tot,vct[o][i]<=m?vct[o][i]+m:vct[o][i]-m);
		++tot;
		addedge(vct[o][i],tot);
		/*if(l==4&&r==4)
			{
				printf("%d %d\n",vct[o][i],tot); 
				continue;
			}*/
		stk[++top]=tot;
		if(top>1)
		{
			/*if(l==4&&r==4)
			{
				printf("%d %d\n",stk[top-1],vct[o][i]<=m?vct[o][i]+m:vct[o][i]-m); 
				continue;
			}*/
			addedge(tot-1,stk[top-1]-1);
			addedge(stk[top-1],tot);
			addedge(vct[o][i],stk[top-1]-1);
			addedge(stk[top-1],vct[o][i]<=m?vct[o][i]+m:vct[o][i]-m);
		}
	}
	if(l==r)
	{
		top=Top;
		return;
	}
	int mid=l+r>>1;
	work(o<<1,l,mid);
	work(o<<1|1,mid+1,r);
	top=Top;
}
void dfs(int x)
{
	v[x]=true;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
			dfs(adj[y]);
	h[++j]=x;
}
void rdfs(int x)
{
	col[x]=num;
	if(x<=2*m)
	Vct[num].push_back(x);
	for(int y=rhead[x];y;y=rnxt[y])
		if(!col[radj[y]])
			rdfs(radj[y]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		aadj[i*2-1]=k;
		nnxt[i*2-1]=hhead[j];
		hhead[j]=i*2-1;
		aadj[i*2]=j;
		nnxt[i*2]=hhead[k];
		hhead[k]=i*2;
	}
	predfs(1,-1);
	tp[1]=1;
	i=0;
	preDfs(1,-1);
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		while(tp[j]!=tp[k])
		{
			if(dep[tp[j]]<dep[tp[k]])
				swap(j,k);
			update(1,1,n,id[tp[j]],id[j],i);
			j=fa[tp[j]];
		}
		if(dep[j]>dep[k])
			swap(j,k);
		if(id[j]<id[k])
		{
			update(1,1,n,id[j]+1,id[k],i);
		}
		scanf("%d%d",&j,&k);
		while(tp[j]!=tp[k])
		{
			if(dep[tp[j]]<dep[tp[k]])
				swap(j,k);
			update(1,1,n,id[tp[j]],id[j],i+m);
			j=fa[tp[j]];
		}
		if(dep[j]>dep[k])
			swap(j,k);
		if(id[j]<id[k])
		{
			update(1,1,n,id[j]+1,id[k],i+m);
		}
	}
	tot=2*m;
	work(1,1,n);
	for(i=1,j=0;i<=tot;++i)
		if(!v[i])
			dfs(i);
	for(;j>=1;--j)
		if(!col[h[j]])
		{
			++num;
			rdfs(h[j]);
		}
	for(i=1;i<=m;++i)
		if(col[i]==col[m+i])
		{
			printf("NO");
			return 0;
		}
	for(i=1;i<=l;++i)
	{
		if(col[adj[i]]!=col[radj[i]])
		{
			Adj[++L]=col[adj[i]];
			Nxt[L]=Head[col[radj[i]]];
			Head[col[radj[i]]]=L;
			++d[Adj[L]];
			//printf("%d %d\n",col[radj[i]],col[adj[i]]);
		}
	}
	//for(i=1;i<=2*m;++i)
	//	printf("%d\n",col[i]);
	//return 0;
	for(i=1;i<=num;++i)
		if(!d[i])
			q[++ed]=i;
	bg=1;
	while(bg<=ed)
	{
		for(i=Head[q[bg]];i;i=Nxt[i])
		{
			--d[Adj[i]];
			if(d[Adj[i]]==0)
				q[++ed]=Adj[i];
		}
		++bg;
	}
	for(i=ed;i>=1;--i)
	{
		for(j=Vct[q[i]].size()-1;j>=0;--j)
			if(w[col[Vct[q[i]][j]<=m?Vct[q[i]][j]+m:Vct[q[i]][j]-m]])
				break;
		if(j<0)
			w[q[i]]=1;
	}
	for(i=1;i<=m;++i)
		if(!w[col[i]]&&!w[col[m+i]])
		{
			printf("NO");
			return 0;
		}
	puts("YES");
	for(i=1;i<=m;++i)
		if(w[col[i]])
			puts("1");
		else
			puts("2");
	return 0;
}