#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1050; 
int a[N][N],c[N][N],n,fa[N],p[N],b[N];
pair<int,int> find(int x)
{
	if(x==fa[x]) return {x,0};
	pair<int,int> t=find(fa[x]);
	fa[x]=t.first; p[x]=(p[x]+t.second)%2;
	return {fa[x],p[x]};
}
void dfs(int x,int y)
{
//	if (b[x]==-1) b[x]=0;
	if (y==n+1) x++,y=1;
	if (x==n+1) return;
	if (x<y)
	{
	  	auto it1=find(x),it2=find(y);
	  	if (it1.first!=it2.first)
	  	{
	  		if (a[x][y]>a[y][x])
			{ 
	  		    fa[it1.first]=it2.first;
	  		    p[it1.first]=1^it1.second^it2.second;
	  		    swap(a[x][y],a[y][x]);
	  	    } else
	  	    if (a[x][y]<a[y][x])
	  	    {
	  		    fa[it1.first]=it2.first;
	  		    p[it1.first]=0^it1.second^it2.second;
	  	    }
	    } else
	    {
	    	int k=it1.second^it2.second;
	    	if(k==1) swap(a[x][y],a[y][x]);
	    }
    }
	dfs(x,y+1); 
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		rep(i,1,n)
		  rep(j,1,n) cin>>a[i][j],c[i][j]=a[i][j];
		rep(i,1,n) b[i]=-1;
		rep(i,1,n) fa[i]=i,p[i]=0;
		dfs(1,1);
	    rep(i,1,n)
	    {
	      rep(j,1,n) cout<<a[i][j]<<" ";
	      cout<<"\n";
	    }
	} 
	return 0;
}
/*
1
4
3 3 1 2
1 1 3 1
3 2 3 2
2 3 3 1
*/