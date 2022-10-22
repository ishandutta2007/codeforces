#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=210;
ll f[N][N][N];
ll a1[N],a2[N],a3[N],x,y,z;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>x>>y>>z;
    rep(i,1,x) cin>>a1[i];
    rep(i,1,y) cin>>a2[i];
    rep(i,1,z) cin>>a3[i];
    sort(a1+1,a1+x+1,cmp);
    sort(a2+1,a2+y+1,cmp);
    sort(a3+1,a3+z+1,cmp);
	rep(i,0,200)
	  rep(j,0,200)
	    rep(k,0,200) f[i][j][k]=-1e10;
	f[0][0][0]=0;
	ll ans=0;
	rep(i,0,x)
	  rep(j,0,y)
	    rep(k,0,z)
	    { 
	      if (i>0&&j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a1[i]*a2[j]);
		  if (i>0&&k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a1[i]*a3[k]);
		  if (j>0&&k>0) f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+a2[j]*a3[k]);
		  ans=max(ans,f[i][j][k]); 
	    }
	cout<<ans<<endl;
	return 0;
}