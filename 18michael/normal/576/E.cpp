#include<bits/stdc++.h>
using namespace std;
int n,m,k,q;
int X[500002],Y[500002],E[500002],C[500002],la[500002],nx[500002],col[500002];
int rt[52][1000002],siz[52][1000002];
typedef pair<int,char> P;
vector<P> vec[2000002];
struct aaa
{
	char c;
	int x,y;
};
inline int getroot(int x,int y)
{
	return y==rt[x][y]? y:getroot(x,rt[x][y]);
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void modify(int k,int l,int r,int l1,int r1,int x,char y)
{
	if(l1>r1)return ;
	if(l>=l1 && r<=r1)
	{
		vec[k].push_back(P(x,y));
		return ;
	}
	int mid=((l+r)>>1);
	if(r1<=mid)modify(lson(k),l,mid,l1,r1,x,y);
	else if(l1>mid)modify(rson(k),mid+1,r,l1,r1,x,y);
	else modify(lson(k),l,mid,l1,mid,x,y),modify(rson(k),mid+1,r,mid+1,r1,x,y);
}
inline void solve(int k,int l,int r)
{
	vector<aaa> vec1;
	for(int i=0,c,rx,ry;i<vec[k].size();++i)
	{
		c=vec[k][i].second,rx=getroot(c,X[vec[k][i].first]),ry=getroot(c,Y[vec[k][i].first]+n);
		if(rx!=ry)
		{
			if(siz[c][rx]>siz[c][ry])swap(rx,ry);
			siz[c][ry]+=siz[c][rx],rt[c][rx]=ry,vec1.push_back((aaa){c,rx,ry});
		}
		rx=getroot(c,X[vec[k][i].first]+n),ry=getroot(c,Y[vec[k][i].first]);
		if(rx!=ry)
		{
			if(siz[c][rx]>siz[c][ry])swap(rx,ry);
			siz[c][ry]+=siz[c][rx],rt[c][rx]=ry,vec1.push_back((aaa){c,rx,ry});
		}
	}
	if(l==r)
	{
		if(getroot(C[l],X[E[l]])==getroot(C[l],Y[E[l]]))
		{
			puts("NO");
			if(col[E[l]])modify(1,1,q,l+1,nx[l]-1,E[l],col[E[l]]);
		}
		else puts("YES"),modify(1,1,q,l+1,nx[l]-1,E[l],col[E[l]]=C[l]);
	}
	else
	{
		int mid=((l+r)>>1);
		solve(lson(k),l,mid),solve(rson(k),mid+1,r);
	}
	for(int i=vec1.size()-1;~i;--i)rt[vec1[i].c][vec1[i].x]=vec1[i].x,siz[vec1[i].c][vec1[i].y]-=siz[vec1[i].c][vec1[i].x];
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;++i)for(int j=1;j<=2*n;++j)rt[i][j]=j,siz[i][j]=1;
	for(int i=1;i<=m;++i)scanf("%d%d",&X[i],&Y[i]);
	for(int i=1;i<=q;++i)scanf("%d%d",&E[i],&C[i]),nx[la[E[i]]]=i,la[E[i]]=i;
	for(int i=1;i<=m;++i)nx[la[i]]=q+1;
	solve(1,1,q);
	return 0;
}