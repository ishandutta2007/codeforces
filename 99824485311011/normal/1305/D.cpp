#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
inline int query(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	if(ret==-1)exit(0);
	return ret;
}
int n;
int dfn[1010],tim;
vector<int> v[1010],leaves;
bool flag[1010];
int rt=-1,rt2=-1;
vector<int> S;
int d[1010];
void dfs1(int np,int fath)
{
	if(!flag[np])return;
	d[np]=d[fath]+1;
	if(rt==-1||d[np]>d[rt])rt=np;
	for(int &x:v[np])
	{
		if(x==fath)continue;
		dfs1(x,np);
	}
}
int fa[1010];
void dfs2(int np,int fath)
{
	if(!flag[np])return;
	fa[np]=fath;
	d[np]=d[fath]+1;
	if(rt2==-1||d[np]>d[rt2])rt2=np;
	for(int &x:v[np])
	{
		if(x==fath)continue;
		dfs2(x,np);
	}
}
void dfs3(int np,int fath)
{
	if(!flag[np])return;
	S.push_back(np);
	for(int &x:v[np])
	{
		if(x==fath)continue;
		dfs3(x,np);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,ti,tj;i<n;i++)
	{
		scanf("%d%d",&ti,&tj);
		v[ti].push_back(tj);
		v[tj].push_back(ti);
	}
	for(int i=1;i<=n;i++)S.push_back(i);
	while(1)
	{
		if(S.size()==1)
		{
			printf("! %d\n",S[0]);
			return 0;
		}
		memset(flag,0,sizeof(flag));
		for(auto &x:S)flag[x]=1;
		rt=-1;
		dfs1(S[0],0);
		rt2=-1;
		dfs2(rt,0);
		int l=query(rt,rt2);
		int p=rt2;
		while(p)flag[p]=0,p=fa[p];
		flag[l]=1;
		S.clear();
		dfs3(l,0);
	}
	return 0;
}