#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int N=300005;
struct node
{
	int id,a,b,l;
}g[N];
struct mode
{
	int id,fa,mxdep,sz;
}s[N];
bool operator <(node a,node b)
{
	if(a.l!=b.l)
		return a.l<b.l;
	return a.id<b.id;
}
set<node> st;
int n,m,i,num,top,fa[N],mxdep[N],sz[N],add[N],mx,ans[N];
vector<node> vct[N*5];
int find(int x)
{
	return !fa[x]?x:find(fa[x]);
}
void Union(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)
		return;
	if(mxdep[x]>mxdep[y])
		swap(x,y);
	s[++top]=(mode){x,fa[x],mxdep[x],sz[x]};
	s[++top]=(mode){y,fa[y],mxdep[y],sz[y]};
	fa[x]=y;
	mxdep[y]=max(mxdep[y],mxdep[x]+1);
	add[top-1]=add[top]=0;
	if(sz[x]&&sz[y])
	{
		num-=2;
		add[top]=2;
	}
	sz[y]^=sz[x];
}
void cirno(int t)
{
	while(top>t)
	{
		fa[s[top].id]=s[top].fa;
		mxdep[s[top].id]=s[top].mxdep;
		sz[s[top].id]=s[top].sz;
		num+=add[top];
		--top;
	}
}
void update(int o,int l,int r,int x,int y,node z)
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
	int t=top;
	for(int i=vct[o].size()-1;i>=0;--i)
		Union(vct[o][i].a,vct[o][i].b);
	if(l==r)
	{
		for(set<node>::iterator ddq=st.begin(),dzx;ddq!=st.end()&&num>0;)
		{
			dzx=ddq;
			ddq++;
			if((dzx->id)>l)
			{
				st.erase(dzx);
				continue;
			}
			Union(dzx->a,dzx->b);
			if((dzx->id)<=l-1)
				update(1,1,m,dzx->id,l-1,*dzx);
			mx=dzx->l;
			st.erase(dzx);
		}
		if(num>0)
			ans[l]=-1;
		else
			ans[l]=mx;
		cirno(t);
		vct[o].clear();
		return;
	}
	int mid=l+r>>1;
	work(o<<1|1,mid+1,r);
	work(o<<1,l,mid);
	cirno(t);
	vct[o].clear();
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&g[i].a,&g[i].b,&g[i].l);
		g[i].id=i;
		st.insert(g[i]);
	}
	num=n;
	for(i=1;i<=n;++i)
		sz[i]=1;
	mx=0;
	work(1,1,m);
	for(i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}