#include<bits/stdc++.h>
#define LD long double
#define inf 1e20
#define eps 1e-8
using namespace std;
int n,m,st_t;
int id[10002],st[10002];
struct Vec
{
	int x,y;
};
vector<Vec> A,B,C;
inline Vec mns(Vec a,Vec b)
{
	return (Vec){a.x-b.x,a.y-b.y};
}
inline int cross(Vec a,Vec b)
{
	return a.x*b.y-a.y*b.x;
}
inline int dot(Vec a,Vec b)
{
	return a.x*b.x+a.y*b.y;
}
inline bool cmp(int x,int y)
{
	return (C[x].x==C[y].x)? (C[x].y<C[y].y):(C[x].x<C[y].x);
}
inline bool check1(Vec a,Vec b,vector<Vec> &In,vector<Vec> &Out)
{
	LD mn=-inf,mx=inf;
	for(int i=0;i<In.size();++i)
	{
		if(fabs(cross(mns(a,In[i]),mns(b,In[i])))<eps)
		{
			if(dot(mns(a,In[i]),mns(b,In[i]))<=0)continue;
			return 0;
		}
		if(cross(mns(a,In[i]),mns(b,In[i]))>0)mn=max(mn,(LD)dot(mns(a,In[i]),mns(b,In[i]))/cross(mns(a,In[i]),mns(b,In[i])));
		else mx=min(mx,(LD)dot(mns(a,In[i]),mns(b,In[i]))/cross(mns(a,In[i]),mns(b,In[i])));
	}
	for(int i=0;i<Out.size();++i)
	{
		if(fabs(cross(mns(a,Out[i]),mns(b,Out[i])))<eps)
		{
			if(dot(mns(a,Out[i]),mns(b,Out[i]))<=0)return 0;
			continue;
		}
		if(cross(mns(a,Out[i]),mns(b,Out[i]))>0)mx=min(mx,(LD)dot(mns(a,Out[i]),mns(b,Out[i]))/cross(mns(a,Out[i]),mns(b,Out[i]))-eps);
		else mn=max(mn,(LD)dot(mns(a,Out[i]),mns(b,Out[i]))/cross(mns(a,Out[i]),mns(b,Out[i]))+eps);
	}
	return mn<=mx;
}
inline bool solve(vector<Vec> &A,vector<Vec> &In,vector<Vec> &Out)
{
	if(check1(A[0],A[1],In,Out))return 1;
	if(A.size()==2)return 0;
	vector<Vec> A1;
	int mx=2;
	for(int i=3;i<A.size();++i)if((LD)dot(mns(A[0],A[i]),mns(A[1],A[i]))/cross(mns(A[0],A[i]),mns(A[1],A[i]))<(LD)dot(mns(A[0],A[mx]),mns(A[1],A[mx]))/cross(mns(A[0],A[mx]),mns(A[1],A[mx])))mx=i;
	A1.push_back(A[mx]);
	for(int i=1;i<mx;++i)A1.push_back(A[i]);
	if(solve(A1,In,Out))return 1;
	A1.clear(),A1.push_back(A[0]);
	for(int i=mx;i<A.size();++i)A1.push_back(A[i]);
	return solve(A1,In,Out);
}
inline bool check(vector<Vec> A,vector<Vec> B)
{
	if(A.size()==1)return 1;
	for(int i=0;i<A.size();++i)id[i]=i;
	C=A,sort(id,id+A.size(),cmp),C.clear(),st_t=0;
	for(int i=0;i<A.size();++i)
	{
		while(st_t>1 && cross(mns(A[st[st_t-1]],A[st[st_t]]),mns(A[id[i]],A[st[st_t]]))<=0)--st_t;
		st[++st_t]=id[i];
	}
	for(int i=1;i<st_t;++i)C.push_back(A[st[i]]);
	st_t=0;
	for(int i=A.size()-1;~i;--i)
	{
		while(st_t>1 && cross(mns(A[st[st_t-1]],A[st[st_t]]),mns(A[id[i]],A[st[st_t]]))<=0)--st_t;
		st[++st_t]=id[i];
	}
	for(int i=1;i<st_t;++i)C.push_back(A[st[i]]);
	return solve(C,A,B);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<n;++i)scanf("%d%d",&x,&y),A.push_back((Vec){x,y});
	for(int i=0,x,y;i<m;++i)scanf("%d%d",&x,&y),B.push_back((Vec){x,y});
	return 0&puts((check(A,B) || check(B,A))? "YES":"NO");
}