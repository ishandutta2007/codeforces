#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
int head[N];
struct re{
	int a,b,c;
}e[N];
int a,b,da,db,l,dis,jl,maxa;
void arr(int x,int y)
{
	e[++l].a=head[x];
	e[l].b=y;
	head[x]=l;
}
void dfs(int x,int y,int z)
{
	if (z>maxa)
	{
		maxa=z; jl=x;
	}
	if (x==b)
	{
		dis=z;
	}
	for (int u=head[x];u;u=e[u].a)
	{
		int v=e[u].b;
		if (v!=y)
		{
			dfs(v,x,z+1);
		}
	}
}
int find(int x)
{
	maxa=0;
	dfs(x,0,0);
	return jl;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
    cin>>T;
    rep(i,1,T)
    {
    	int n;
    	cin>>n>>a>>b>>da>>db;
    	rep(i,1,n-1)
    	{
    		int x,y;
    		cin>>x>>y;
    		arr(x,y); arr(y,x);
    	}
    	dfs(a,0,0);
    	int dis2=dis;
    	int k;
		k=find(1);
		k=find(k);
		if (maxa>2*da&&dis2>da&&db>2*da)
		  cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
    	rep(i,1,n) head[i]=0;
    	l=0;
    }
	return 0;
}