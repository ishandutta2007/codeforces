#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define pb push_back
#define mp std::make_pair
#define ls d<<1
#define rs d<<1|1

typedef std::pair<int,int> pi;

const int N=200005;

int n,m,f[N],s[N],tim,pos[N],bel[N],sz,top,rev[N*2],ans[N];
pi stack[N];
std::map<pi,int> ma;
std::vector<pi> tag[N*4];
std::vector<int> vec[N*2];
struct data{int op,x,y;}p[N];
struct edge{int x,y;}e[N*2];

void ins(int d,int l,int r,int x,int y,int z,int op)
{
	if (x<=l&&r<=y) {tag[d].pb(mp(z,op));return;}
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z,op);
	if (y>mid) ins(rs,mid+1,r,x,y,z,op);
}

int find(int x)
{
	if (f[x]==x) return x;
	else return find(f[x]);
}

void add(int w)
{
	int x=find(e[w].x),y=find(e[w].y);
	if (x==y) return;
	if (s[x]>s[y]) std::swap(x,y);
	f[x]=y;s[y]+=s[x];stack[++top]=mp(x,y);
}

void back(int now)
{
	while (top>now)
	{
		int x=stack[top].first,y=stack[top].second;
		top--;
		s[y]-=s[x];f[x]=x;
	}
}

void solve(int d,int l,int r)
{
	if (l==r)
	{
		int tmp=top;
		for (int i=0;i<tag[d].size();i++)
			if (tag[d][i].second==rev[tag[d][i].first]) add(tag[d][i].first);
		ans[l]=find(p[bel[l]].x)==find(p[bel[l]].y);
		back(tmp);
		if (l==tim) return;
		p[bel[l+1]].x=(p[bel[l+1]].x+ans[l]-1)%n+1;p[bel[l+1]].y=(p[bel[l+1]].y+ans[l]-1)%n+1;
		for (int i=bel[l]+1;i<bel[l+1];i++)
		{
			int x=(p[i].x+(ans[l]^1)-1)%n+1,y=(p[i].y+(ans[l]^1)-1)%n+1;
			if (x>y) std::swap(x,y);
			rev[ma[mp(x,y)]]^=1;
		}
		return;
	}
	int mid=(l+r)/2,tmp=top;
	for (int i=0;i<tag[d].size();i++)
		if (tag[d][i].second==rev[tag[d][i].first]) add(tag[d][i].first);
	solve(ls,l,mid);
	back(tmp);
	for (int i=0;i<tag[d].size();i++)
		if (tag[d][i].second==rev[tag[d][i].first]) add(tag[d][i].first);
	solve(rs,mid+1,r);
	back(tmp);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&p[i].op,&p[i].x,&p[i].y);
		if (p[i].op==1)
		{
			int x=(p[i].x-1)%n+1,y=(p[i].y-1)%n+1;
			if (x>y) std::swap(x,y);
			if (!ma[mp(x,y)]) ma[mp(x,y)]=++sz,e[sz].x=x,e[sz].y=y;
			vec[ma[mp(x,y)]].pb(i);
			if (!tim) continue;
			x=p[i].x%n+1;y=p[i].y%n+1;
			if (x>y) std::swap(x,y);
			if (!ma[mp(x,y)]) ma[mp(x,y)]=++sz,e[sz].x=x,e[sz].y=y;
			pos[i]=tim;
			vec[ma[mp(x,y)]].pb(i);
		}
		else
		{
			pos[i]=++tim;bel[tim]=i;
		}
	}
	for (int i=1;i<=sz;i++)
	{
		for (int j=0;j<vec[i].size()-1;j++)
			if (pos[vec[i][j]]<pos[vec[i][j+1]]) ins(1,1,tim,pos[vec[i][j]]+1,pos[vec[i][j+1]],i,j&1);
		int t=vec[i].back();
		if (pos[t]<tim) ins(1,1,tim,pos[t]+1,tim,i,(vec[i].size()&1)^1);
	}
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1;
	solve(1,1,tim);
	for (int i=1;i<=tim;i++) putchar(ans[i]+'0');
	return 0;
}