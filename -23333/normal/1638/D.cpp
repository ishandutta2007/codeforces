#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define ll long long
const int P=998244353;
map<int,int> M;
const int N=1050;
int a[N][N],b[N][N],c[N][N];
struct re{
	int a,b,c;
};
queue<re> q;
vector<re> ans;
int n,m;
int cl(int x,int y)
{
	if (!c[x][y])
	{
		
		c[x][y]=1;
		rep(i,0,1)
		  rep(j,0,1)
		    {
					int X=x-i,Y=y-j;
					bool tt=1;
					rep(i1,0,1)
					  rep(j1,0,1)
					    rep(i2,0,1)
					      rep(j2,0,1)
					        if (a[X+i1][Y+j1]!=a[X+i2][Y+j2]&&!c[X+i1][Y+j1]&&!c[X+i2][Y+j2])
							   tt=0; 
				    if (X!=0&&Y!=0&&X!=n&&Y!=m&&tt) q.push({X,Y});
			}
			return a[x][y];
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>n>>m;
	rep(i,1,n)
	  rep(j,1,m) cin>>a[i][j];
	rep(i,1,n-1)
	  rep(j,1,m-1)
	  {
	  	if (a[i+1][j]&&a[i+1][j]!=a[i][j]) b[i][j]++;
	  	if (a[i+1][j+1]&&a[i+1][j+1]!=a[i][j]) b[i][j]++;
	  	if (a[i][j+1]&&a[i][j+1]!=a[i][j]) b[i][j]++;
	  	if (!b[i][j]) q.push((re){i,j});
	  }
	while (!q.empty())
	{
		re x=q.front(); q.pop();
	//	cout<<x.a<<" "<<x.b<<endl;
		int co=0;
		rep(i,0,1)
		  rep(j,0,1)
		  {
		    co=max(co,cl(x.a+i,x.b+j));
		  }
		if (co) ans.push_back({x.a,x.b,co});
	}
	bool tt=0; 
	rep(i,1,n)
	  rep(j,1,m)
	    if (!c[i][j]) tt=1;
	if (tt)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	reverse(ans.begin(),ans.end());
	for(auto v:ans)
	  cout<<v.a<<" "<<v.b<<" "<<v.c<<endl;
	return 0;
}