#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<stack>
using namespace std;
const int N=1000005;
struct node
{
	int x,p,mxdep;
};
stack<node> s;
int n,m,ty[N],x[N][2],y[N][2],nxt[N][2],p[N],mxdep[N],size;
map<int,int> mp[N];
set<int> st[N];
vector<int> vct1[N*5],vct2[N*5];
bool v[N],lst;
inline void Read(int &x)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
}
int dzx;
void update(int o,int l,int r,int x,int y,int u,int v)
{
	if(l>=x&&r<=y)
	{
		vct1[o].push_back(u),vct2[o].push_back(v);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y,u,v);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,u,v);
}
int find(int x)
{
	return !p[x]?x:find(p[x]);
}
void Union(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)
		return;
	if(mxdep[x]>mxdep[y])
		swap(x,y);
	s.push((node){x,p[x],mxdep[x]});
	s.push((node){y,p[y],mxdep[y]});
	size+=2;
	p[x]=y;
	mxdep[y]=max(mxdep[y],mxdep[x]+1);
}
void work(int o,int l,int r)
{
	int bg=size;
	for(int i=vct1[o].size()-1;i>=0;--i)
		Union(vct1[o][i],vct2[o][i]);
	if(l==r)
	{
		if(ty[l]==1)
		{
			if(lst==0)
			{
				if(!st[x[l][0]].count(y[l][0]))
				{
					if(l+1<=nxt[l][0]-1)
						update(1,1,m,l+1,nxt[l][0]-1,x[l][0],y[l][0]);
					st[x[l][0]].insert(y[l][0]);
				}
				else
					st[x[l][0]].erase(y[l][0]);
				if(st[x[l][1]].count(y[l][1])&&l+1<=nxt[l][1]-1)
					update(1,1,m,l+1,nxt[l][1]-1,x[l][1],y[l][1]);
			}
			else
			{
				if(!st[x[l][1]].count(y[l][1]))
				{
					if(l+1<=nxt[l][1]-1)
						update(1,1,m,l+1,nxt[l][1]-1,x[l][1],y[l][1]);
					st[x[l][1]].insert(y[l][1]);
				}
				else
					st[x[l][1]].erase(y[l][1]);
				if(st[x[l][0]].count(y[l][0])&&l+1<=nxt[l][0]-1)
					update(1,1,m,l+1,nxt[l][0]-1,x[l][0],y[l][0]);
			}
		}
		else
		{
			int a,b;
			if(lst)
				a=x[l][1],b=y[l][1];
			else
				a=x[l][0],b=y[l][0];
			if(find(a)==find(b))
			{
				printf("1");
				v[l]=true;
			}
			else
			{
				printf("0");
				v[l]=false;
			}
			lst=v[l];
		}
		while(size>bg)
		{
			p[s.top().x]=s.top().p;
			mxdep[s.top().x]=s.top().mxdep;
			s.pop();
			--size;
		}
		return;
	}
	int mid=l+r>>1;
	work(o<<1,l,mid);
	work(o<<1|1,mid+1,r);
	while(size>bg)
	{
		p[s.top().x]=s.top().p;
		mxdep[s.top().x]=s.top().mxdep;
		s.pop();
		--size;
	}
}
int main()
{
	Read(n);Read(m);
	int i;
	for(i=1;i<=m;++i)
	{
		Read(ty[i]);Read(x[i][0]);Read(y[i][0]);
		x[i][1]=x[i][0]%n+1,y[i][1]=y[i][0]%n+1;
		if(x[i][0]>y[i][0])
			swap(x[i][0],y[i][0]);
		if(x[i][1]>y[i][1])
			swap(x[i][1],y[i][1]);
	}
	for(i=m;i>=1;--i)
	if(ty[i]==1)
	{
		if(mp[x[i][0]].count(y[i][0]))
			nxt[i][0]=mp[x[i][0]][y[i][0]];
		else
			nxt[i][0]=m+1;
		if(mp[x[i][1]].count(y[i][1]))
			nxt[i][1]=mp[x[i][1]][y[i][1]];
		else
			nxt[i][1]=m+1;
		mp[x[i][0]][y[i][0]]=mp[x[i][1]][y[i][1]]=i;
	}
	work(1,1,m);
	return 0;
}