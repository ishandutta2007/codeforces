#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
const int N=400004,INF=999999999;
using namespace std;

int n,m;
vector<int> a[N];
long long sg[N],one=1;
vector<int> v;
long long st[2500000],laz[2500000];
pair<int,int> ah[N];
int ans;
long long ast[70];
void dfs(int x,int p)
{
	int i,j,k;
	v.push_back(x);
	for(i=0;i<a[x].size();++i)
	{
		k=a[x][i];
		if(k==p)continue;
		dfs(k,x);
		v.push_back(x);
	}
}
void sift(int pos)
{
	if(laz[pos])
		st[pos*2]=st[pos*2+1]=laz[pos*2]=laz[pos*2+1]=laz[pos];
	laz[pos]=0;
}
void create(int tl,int tr,int pos)
{
	if(tl==tr)
	{
		st[pos]=ast[sg[v[tl]]];
		return;
	}
	int me=(tl+tr)/2;
	create(tl,me,pos<<1);
	create(me+1,tr,(pos<<1)+1);
	st[pos]=st[pos<<1]|st[(pos<<1)+1];
}
void ubd(int tl,int tr,int l,int r,int pos,long long x)
{
	if(tl==l && tr==r)
	{
		st[pos]=ast[x];
		laz[pos]=st[pos];
		return;
	}
	sift(pos);
	int me=(tl+tr)>>1;
	if(r<=me)
	{
		ubd(tl,me,l,r,pos<<1,x);
	}
	else if(l>me)
	{
		ubd(me+1,tr,l,r,(pos<<1)+1,x);
	}
	else
	{
		ubd(tl,me,l,me,pos<<1,x);
		ubd(me+1,tr,me+1,r,(pos<<1)+1,x);
	}
	st[pos]=st[pos<<1]|st[(pos<<1)+1];
}
long long query(int tl,int tr,int l,int r,int pos)
{
	if(tl==l && tr==r)
	{
		return st[pos];
	}
	sift(pos);
	int me=(tl+tr)>>1;
	if(r<=me)
	{
		return query(tl,me,l,r,pos<<1);
	}
	else if(l>me)
	{
		return query(me+1,tr,l,r,(pos<<1)+1);
	}
	else
	{
		return query(tl,me,l,me,pos<<1)|query(me+1,tr,me+1,r,(pos<<1)+1);
	}
}
int main()
{
	int i,j,k,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&sg[i]);
		ah[i].first=INF;
	}
	for(i=0;i<n-1;++i)
	{
		scanf("%d%d",&j,&k);
		a[j].push_back(k);
		a[k].push_back(j);
	}
	ast[0]=1;
	for(i=1;i<=62;++i)
	{
		ast[i]=(ast[i-1]<<1);
	}
	dfs(1,-1);
	for(i=0;i<v.size();++i)
	{
		ah[v[i]].first=min(ah[v[i]].first,i);
		ah[v[i]].second=max(ah[v[i]].second,i);
	}
	create(0,v.size()-1,1);
	for(i=0;i<m;++i)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d",&x,&y);
			ubd(0,v.size()-1,ah[x].first,ah[x].second,1,y);
		}
		else
		{
			scanf("%d",&x);
			long long z=query(0,v.size()-1,ah[x].first,ah[x].second,1);
			ans=0;
			while(z)
			{
				if(z&1)
					++ans;
				z=z>>1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}