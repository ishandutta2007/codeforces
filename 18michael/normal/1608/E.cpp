#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=0,l0,l1,res;
int idx[100002],idy[100002],rkx[100002],rky[100002],c[4],t[4];
bool u[4]={};
struct aaa
{
	int x,y,c;
}p[100002];
inline bool cmpx(int a,int b)
{
	return p[a].x==p[b].x? (p[a].y<p[b].y):(p[a].x<p[b].x);
}
inline bool cmpy(int a,int b)
{
	return p[a].y==p[b].y? (p[a].x<p[b].x):(p[a].y<p[b].y);
}
inline void solve1()
{
	for(l0=1,l1=n,t[1]=t[3]=0,t[2]=n/3;;)
	{
		for(;t[1]<=t[3] && l0+1<l1;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idx[l0]].x;l0+1<l1 && p[idx[l0]].x==res;++l0)
			{
				if(p[idx[l0]].c==c[1])++t[1];
				if(p[idx[l0]].c==c[2])--t[2];
			}
		for(;t[3]<=t[1] && l0+1<l1;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idx[l1]].x;l0+1<l1 && p[idx[l1]].x==res;--l1)
			{
				if(p[idx[l1]].c==c[3])++t[3];
				if(p[idx[l1]].c==c[2])--t[2];
			}
		if(l0+1>=l1)return ;
	}
}
inline void solve2()
{
	for(l0=1,l1=n,t[1]=t[3]=0,t[2]=n/3;;)
	{
		for(;t[1]<=t[3] && l0+1<l1;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idy[l0]].y;l0+1<l1 && p[idy[l0]].y==res;++l0)
			{
				if(p[idy[l0]].c==c[1])++t[1];
				if(p[idy[l0]].c==c[2])--t[2];
			}
		for(;t[3]<=t[1] && l0+1<l1;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idy[l1]].y;l0+1<l1 && p[idy[l1]].y==res;--l1)
			{
				if(p[idy[l1]].c==c[3])++t[3];
				if(p[idy[l1]].c==c[2])--t[2];
			}
		if(l0+1>=l1)return ;
	}
}
inline void solve3()
{
	for(l0=1,l1=1,t[1]=t[3]=0,t[2]=n/3;;)
	{
		for(;t[1]<=t[3] && l0<=n;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idx[l0]].x;l0<=n && p[idx[l0]].x==res;++l0)
			{
				if(p[idx[l0]].c==c[1])++t[1];
				if(p[idx[l0]].c==c[2] && rky[idx[l0]]>=l1)--t[2];
				if(p[idx[l0]].c==c[3] && rky[idx[l0]]<l1)--t[3];
			}
		for(;t[3]<=t[1] && l1<=n;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idy[l1]].y;l1<=n && p[idy[l1]].y==res;++l1)
			{
				if(p[idy[l1]].c==c[3] && rkx[idy[l1]]>=l0)++t[3];
				if(p[idy[l1]].c==c[2] && rkx[idy[l1]]>=l0)--t[2];
			}
		if((l0>n && t[1]<=t[3]) || (l1>n && t[3]<=t[1]))return ;
	}
}
inline void solve4()
{
	for(l0=n,l1=1,t[1]=t[3]=0,t[2]=n/3;;)
	{
		for(;t[1]<=t[3] && l0;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idx[l0]].x;l0 && p[idx[l0]].x==res;--l0)
			{
				if(p[idx[l0]].c==c[1])++t[1];
				if(p[idx[l0]].c==c[2] && rky[idx[l0]]>=l1)--t[2];
				if(p[idx[l0]].c==c[3] && rky[idx[l0]]<l1)--t[3];
			}
		for(;t[3]<=t[1] && l1<=n;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idy[l1]].y;l1<=n && p[idy[l1]].y==res;++l1)
			{
				if(p[idy[l1]].c==c[3] && rkx[idy[l1]]<=l0)++t[3];
				if(p[idy[l1]].c==c[2] && rkx[idy[l1]]<=l0)--t[2];
			}
		if((!l0 && t[1]<=t[3]) || (l1>n && t[3]<=t[1]))return ;
	}
}
inline void solve5()
{
	for(l0=1,l1=1,t[1]=t[3]=0,t[2]=n/3;;)
	{
		for(;t[1]<=t[3] && l0<=n;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idy[l0]].y;l0<=n && p[idy[l0]].y==res;++l0)
			{
				if(p[idy[l0]].c==c[1])++t[1];
				if(p[idy[l0]].c==c[2] && rkx[idy[l0]]>=l1)--t[2];
				if(p[idy[l0]].c==c[3] && rkx[idy[l0]]<l1)--t[3];
			}
		for(;t[3]<=t[1] && l1<=n;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idx[l1]].x;l1<=n && p[idx[l1]].x==res;++l1)
			{
				if(p[idx[l1]].c==c[3] && rky[idx[l1]]>=l0)++t[3];
				if(p[idx[l1]].c==c[2] && rky[idx[l1]]>=l0)--t[2];
			}
		if((l0>n && t[1]<=t[3]) || (l1>n && t[3]<=t[1]))return ;
	}
}
inline void solve6()
{
	for(l0=n,l1=1,t[1]=t[3]=0,t[2]=n/3;;)
	{
		for(;t[1]<=t[3] && l0;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idy[l0]].y;l0 && p[idy[l0]].y==res;--l0)
			{
				if(p[idy[l0]].c==c[1])++t[1];
				if(p[idy[l0]].c==c[2] && rkx[idy[l0]]>=l1)--t[2];
				if(p[idy[l0]].c==c[3] && rkx[idy[l0]]<l1)--t[3];
			}
		for(;t[3]<=t[1] && l1<=n;ans=max(ans,min(min(t[1],t[2]),t[3])))
			for(res=p[idx[l1]].x;l1<=n && p[idx[l1]].x==res;++l1)
			{
				if(p[idx[l1]].c==c[3] && rky[idx[l1]]<=l0)++t[3];
				if(p[idx[l1]].c==c[2] && rky[idx[l1]]<=l0)--t[2];
			}
		if((!l0 && t[1]<=t[3]) || (l1>n && t[3]<=t[1]))return ;
	}
}
inline void dfs(int x,int y)
{
	if(x>3)
	{
		if(y==1)solve1();
		else if(y==2)solve2();
		else if(y==3)solve3();
		else if(y==4)solve4();
		else if(y==5)solve5();
		else solve6();
		return ;
	}
	for(int i=1;i<=3;++i)if(!u[i])u[c[x]=i]=1,dfs(x+1,y),u[i]=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].c),idx[i]=idy[i]=i;
	sort(idx+1,idx+n+1,cmpx),sort(idy+1,idy+n+1,cmpy);
	for(int i=1;i<=n;++i)rkx[idx[i]]=i,rky[idy[i]]=i;
	for(int i=1;i<=6;++i)dfs(1,i);
	return 0&printf("%d",3*ans);
}