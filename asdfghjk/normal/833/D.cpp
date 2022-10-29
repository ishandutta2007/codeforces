#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200005,md=1000000007;
struct node
{
	int adj,col,len;
};
vector<node> vct[N];
int n,i,j,k,x,y,root,c[2*N],sz[N],mx[N],ans;
bool v[N];
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
void Dfs(int x,int dad,int size)
{
	sz[x]=1;
	mx[x]=0;
	for(int y=0;y<vct[x].size();++y)
		if(vct[x][y].adj!=dad&&!v[vct[x][y].adj])
		{
			Dfs(vct[x][y].adj,x,size);
			sz[x]+=sz[vct[x][y].adj];
			mx[x]=max(mx[x],sz[vct[x][y].adj]);
		}
	mx[x]=max(mx[x],size-sz[x]);
	if(!root||mx[x]<mx[root])
		root=x;
}
void add(int x,int y)
{
	while(x<2*N)
	{
		c[x]+=y;
		x+=x&-x;
	}
}
int sum(int x)
{
	int rtn=0;
	while(x)
	{
		rtn+=c[x];
		x-=x&-x;
	}
	return rtn;
}
void dzx(int x,int dad,int d,int a,int b,int w)
{
	add(N+d,w);
	for(int y=0;y<vct[x].size();++y)
		if(!v[vct[x][y].adj]&&vct[x][y].adj!=dad)
			dzx(vct[x][y].adj,x,d+(vct[x][y].col?a:b),a,b,w);
}
void work(int x,int dad,int mt,int d,int a,int b,bool t)
{
	if(t&&d<0)
		ans=1ll*ans*mt%md;
	ans=1ll*ans*pw(mt,sum(N-d-1))%md;
	for(int y=0;y<vct[x].size();++y)
		if(!v[vct[x][y].adj]&&vct[x][y].adj!=dad)
			work(vct[x][y].adj,x,1ll*mt*vct[x][y].len%md,d+(vct[x][y].col?a:b),a,b,t);
}
void dfs(int x,int size)
{
	root=0;
	Dfs(x,-1,size);
	v[root]=true;
	for(int y=0;y<vct[root].size();++y)
		if(!v[vct[root][y].adj])
		{
			work(vct[root][y].adj,root,vct[root][y].len,vct[root][y].col?-1:2,-1,2,true);
			dzx(vct[root][y].adj,root,vct[root][y].col?-1:2,-1,2,1);
		}
	for(int y=0;y<vct[root].size();++y)
		if(!v[vct[root][y].adj])
			dzx(vct[root][y].adj,root,vct[root][y].col?-1:2,-1,2,-1);
	for(int y=vct[root].size()-1;y>=0;--y)
		if(!v[vct[root][y].adj])
		{
			work(vct[root][y].adj,root,vct[root][y].len,vct[root][y].col?-1:2,-1,2,false);
			dzx(vct[root][y].adj,root,vct[root][y].col?-1:2,-1,2,1);
		}
	for(int y=vct[root].size()-1;y>=0;--y)
		if(!v[vct[root][y].adj])
			dzx(vct[root][y].adj,root,vct[root][y].col?-1:2,-1,2,-1);
	for(int y=0;y<vct[root].size();++y)
		if(!v[vct[root][y].adj])
		{
			work(vct[root][y].adj,root,vct[root][y].len,vct[root][y].col?2:-1,2,-1,true);
			dzx(vct[root][y].adj,root,vct[root][y].col?2:-1,2,-1,1);
		}
	for(int y=0;y<vct[root].size();++y)
		if(!v[vct[root][y].adj])
			dzx(vct[root][y].adj,root,vct[root][y].col?2:-1,2,-1,-1);
	for(int y=vct[root].size()-1;y>=0;--y)
		if(!v[vct[root][y].adj])
		{
			work(vct[root][y].adj,root,vct[root][y].len,vct[root][y].col?2:-1,2,-1,false);
			dzx(vct[root][y].adj,root,vct[root][y].col?2:-1,2,-1,1);
		}
	for(int y=vct[root].size()-1;y>=0;--y)
		if(!v[vct[root][y].adj])
			dzx(vct[root][y].adj,root,vct[root][y].col?2:-1,2,-1,-1);
	int rt=root;
	for(int y=0;y<vct[rt].size();++y)
		if(!v[vct[rt][y].adj])
			dfs(vct[rt][y].adj,sz[vct[rt][y].adj]);
}
void cirno(int x,int dad)
{
	sz[x]=1;
	for(int y=0;y<vct[x].size();++y)
		if(vct[x][y].adj!=dad)
		{
			cirno(vct[x][y].adj,x);
			sz[x]+=sz[vct[x][y].adj];
			ans=1ll*ans*pw(vct[x][y].len,1ll*sz[vct[x][y].adj]*(n-sz[vct[x][y].adj])%(md-1))%md;
		}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d%d",&j,&k,&x,&y);
		vct[j].push_back((node){k,y,x});
		vct[k].push_back((node){j,y,x});
	}
	ans=1;
	dfs(1,n);
	ans=pw(ans,md-2);
	cirno(1,-1);
	printf("%d",ans);
	return 0;
}