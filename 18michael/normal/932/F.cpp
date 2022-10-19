#include<bits/stdc++.h>
#define LL __int128
#define LD long double
#define eps 1e-10
using namespace std;
int n,edge_t=0;
bool ok;
int a[100002],b[100002],la[100002],id[100002];
LL dp[100002];
struct Vec
{
	int x;
	LL y;
	inline bool operator < (const Vec &a) const
	{
		return x==a.x? y<a.y:x<a.x;
	}
}tmp1,tmp2,tmp3;
set<Vec> s[100002];
set<Vec>::iterator it,it1,it2,it3;
inline Vec mns(Vec a,Vec b)
{
	return (Vec){a.x-b.x,a.y-b.y};
}
inline LL cross(Vec a,Vec b)
{
	return a.x*b.y-a.y*b.x;
}
inline void del(int x,Vec a,Vec b);
inline void ins(int x,Vec a,Vec b);
inline void Ins(int x,Vec a)
{
	if(s[x].count(a) || ((it1=s[x].lower_bound(a))!=s[x].end() && it1!=s[x].begin() && cross(mns(*it1,a),mns(*(--(it2=it1)),a))<=0))return ;
	while(it1!=s[x].end() && (++(it2=it1))!=s[x].end() && cross(mns(a,*it1),mns(*it2,*it1))>=0)
	{
		ok=(it1!=s[x].begin()),tmp1=(*it1),tmp2=(*it2);
		if(ok)tmp3=(*(--(it3=it1)));
		del(x,tmp1,tmp2);
		if(ok)del(x,tmp3,tmp1);
		
		assert(it1!=s[x].end());
		
		it1=s[x].erase(it1);
		if(ok)ins(x,tmp3,tmp2);
	}
	while(it1!=s[x].begin() && (it2=(--it1))!=s[x].begin() && cross(mns(a,*it1),mns(*(--it2),*it1))<=0)
	{
		tmp1=(*it1),tmp2=(*it2),ok=((++(it3=it1))!=s[x].end());
		if(ok)tmp3=(*it3);
		del(x,tmp2,tmp1);
		if(ok)del(x,tmp1,tmp3);
		
		assert(it1!=s[x].end());
		
		it1=s[x].erase(it1);
		if(ok)ins(x,tmp2,tmp3);
	}
	
	it1=s[x].lower_bound(a);
	if(it1!=s[x].begin())ins(x,*(--(it2=it1)),a);
	if(it1!=s[x].end())ins(x,a,*it1);
	if(it1!=s[x].end() && it1!=s[x].begin())del(x,*it2,*it1);
	s[x].insert(a);
}
struct bbb
{
	LD k;
	Vec x,y;
	inline bool operator < (const bbb &a) const
	{
		return k==a.k? x<a.x:k<a.k;
	}
};
set<bbb> s1[100002];
set<bbb>::iterator It;
inline void del(int x,Vec a,Vec b)
{
	s1[x].erase((bbb){(LD)(b.y-a.y)/(b.x-a.x+eps),a,b});
}
inline void ins(int x,Vec a,Vec b)
{
	//printf(" %d\n",a.x-b.x);
	s1[x].insert((bbb){(LD)(b.y-a.y)/(b.x-a.x+eps),a,b});
}
struct aaa
{
	int to,nx;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	//printf("DFS %d %d\n",x,f);
	dp[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x);
			if(s[id[v]].size()>s[id[x]].size())swap(id[v],id[x]),s1[id[v]].clear();
			for(it=s[id[v]].begin();it!=s[id[v]].end();it=s[id[v]].erase(it))Ins(id[x],*it);
		}
	
	/*printf("  before s %d:",x);
	for(it=s[id[x]].begin();it!=s[id[x]].end();++it)printf("(%d,%lld)",(*it).x,(*it).y);
	printf("\n  s1 %d:",x);
	for(It=s1[id[x]].begin();It!=s1[id[x]].end();++It)printf("(%Lf,(%d,%lld),(%d,%lld))",(*It).k,(*It).x.x,(*It).x.y,(*It).y.x,(*It).y.y);
	puts("");*/
	
	//for(it=s[id[x]].begin();it!=s[id[x]].end();++it)dp[x]=max(dp[x],(LL)(*it).x*a[x]+(*it).y);
	if((It=s1[id[x]].lower_bound((bbb){-a[x],(Vec){-1000000,0},(Vec){0,0}}))!=s1[id[x]].end())dp[x]=(LL)(*It).x.x*a[x]+(*It).x.y/*,puts(" CS 1")*/;
	else if(!s[id[x]].empty())--(it=s[id[x]].end()),dp[x]=(LL)(*it).x*a[x]+(*it).y/*,puts(" CS 2")*/;
	Ins(id[x],(Vec){b[x],dp[x]});
	
	/*printf("  after s %d:",x);
	for(it=s[id[x]].begin();it!=s[id[x]].end();++it)printf("(%d,%lld)",(*it).x,(*it).y);
	printf("\n  s1 %d:",x);
	for(It=s1[id[x]].begin();It!=s1[id[x]].end();++It)printf("(%Lf,(%d,%lld),(%d,%lld))",(*It).k,(*It).x.x,(*It).x.y,(*It).y.x,(*It).y.y);
	puts("");*/
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[i]=i;
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0);
	for(int i=1;i<=n;++i)printf("%lld ",(long long)dp[i]);
	return 0;
}