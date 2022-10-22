#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1000;
const int mo=998244353;
int dis[N][N];
int head[N],l,n,m;
struct re{
	int a,b;
}e[N*2];
void arr(int x,int y)
{
	e[++l].a=head[x];
	e[l].b=y;
	head[x]=l;
}
int js(int x,int y)
{
	int cnt=0;
	rep(i,1,n) if (dis[x][i]+dis[i][y]==dis[x][y]) cnt++;
	if (cnt!=dis[x][y]+1) return 0;
	ll ans=1;
	rep(i,1,n)
	{
		if(dis[x][i]+dis[i][y]==dis[x][y]) continue;
		ll num=0;
		for (int u=head[i];u;u=e[u].a)
		{
			int v=e[u].b;
			if (dis[x][v]+1==dis[x][i]&&dis[y][v]+1==dis[y][i]) num++;
		}
		ans=ans*num%mo;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,1,n)
	  rep(j,1,n) dis[i][j]=1e9;
	rep(i,1,n) dis[i][i]=0;
	rep(i,1,m)
	{
		int x,y;
		cin>>x>>y; arr(x,y); arr(y,x);
		dis[x][y]=dis[y][x]=1;
	}
	rep(i,1,n)
	  rep(j,1,n)
	    rep(k,1,n)
	      dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    rep(i,1,n)
    {
      rep(j,1,n) 
        cout<<js(i,j)<<" ";
	  cout<<endl;
    }
	return 0;
}