#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
int n,m,q;
map<pair<int,int>,bool >M;
const int N=2.1e5;
int f[2][N];
inline void maxa(int &x,int y)
{
	if (y>x) x=y; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	bool tt=0;
	if (n>m) {swap(n,m); tt=1;}
	cin>>q;
	rep(i,1,q)
	{
		int x,y;
		cin>>x>>y;
		if(tt) swap(x,y);
		M[make_pair(x,y)]=1;
    }
	f[1][1]=1;
	rep(i,1,1e6)
	{
		rep(j,1,n) f[0][j]=f[1][j],f[1][j]=0;
		rep(j,1,n)
		  if(f[0][j])
		  {
		  	maxa(f[1][j],f[0][j]);
		    maxa(f[1][j],j+f[0][j]+M[make_pair(j,f[0][j])]);
		    f[1][j]=min(f[1][j],m);
			maxa(f[1][min(n,j+f[0][j]+M[make_pair(j,f[0][j])])],f[0][j]);
		  }
		if (f[1][n]==m)
		{
			cout<<i<<endl;
			return 0;
	    }
	}
	return 0; 
}