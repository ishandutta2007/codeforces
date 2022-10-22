#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=2e5;
#define mid ((h+t)/2)
struct sgt{
	int v[N*4][3][3];
	void updata(int x)
	{
		rep(i,0,2)
		  rep(j,0,2)
		    v[x][i][j]=1e9;
		rep(i,0,2)
		  rep(j,0,2)
		    rep(k,0,2)
		      v[x][i][k]=min(v[x][i][k],v[x*2][i][j]+v[x*2+1][j][k]);
	}
	void g(int x,int h,int t,int pos,int k)
	{
		if (h==t)
		{
			v[x][0][0]=(k==0);
			v[x][1][1]=(k==1);
			v[x][2][2]=(k==2);
			rep(i,0,2)
			  rep(j,0,2)
			    if (j<i) v[x][i][j]=1e9;
			return;
	    }
	    if (pos<=mid) g(x*2,h,mid,pos,k);
	    else g(x*2+1,mid+1,t,pos,k);
	    updata(x);
	}
}S;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	cin>>(s+1);
	rep(i,1,n) S.g(1,1,n,i,s[i]-'a');
	rep(i,1,q)
	{
	  int x; char y;
	  cin>>x>>y;
	  S.g(1,1,n,x,y-'a');
	  int ans=1e9; 
	  rep(i,0,2)
	    rep(j,0,2)
	      ans=min(ans,S.v[1][i][j]);
	  cout<<ans<<endl;
	}
	return 0; 
}