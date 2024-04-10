#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=3e5+10;
int a[N],T,n;
char c[N];
bool b[N],d[N];
int f[N][2][2];
bool check(int x,int y,int z)
{
	if (x==y&&x==z) return 0; else return 1;
}
int dp()
{
   rep(i,1,n)
     rep(j,0,1)
       rep(k,0,1) f[i][j][k]=1e9;
   f[2][d[2]][d[1]]=0;
   rep(i,3,n-1)
   {
   	 rep(j,0,1)
   	 {
   	   int cnt=0;
   	   if (j!=d[i]) cnt=1;
   	   rep(k,0,1)
   	   {
   	   	  if (j==k) f[i][j][k]=f[i-1][k][k^1]+cnt;
	      else f[i][j][k]=min(f[i-1][k][0],f[i-1][k][1])+cnt; 
   	   }
     }
   }
   int ans=1e9;
   rep(j,0,1)
     rep(k,0,1)
       if (!((j==k&&k==d[n])||(j==d[n]&&d[n]==d[1]))) ans=min(ans,f[n-1][j][k]);
   return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	rep(i,1,T)
	{
		cin>>n; cin>>c;
		int ans=1e9;
		rep(i,0,n-1) if (c[i]=='R') b[i+1]=1; else b[i+1]=0;
		rep(i,0,1)
		  rep(j,0,1)
		    rep(k,0,1)
		    {
		        memcpy(d,b,sizeof(b));
		    	if (i==1) d[n]^=1;
		    	if (j==1) d[1]^=1;
		    	if (k==1) d[2]^=1;
		    	if (check(d[n],d[1],d[2])) 
				  ans=min(ans,dp()+i+j+k);
		    }
		cout<<ans<<endl;
	}
	return 0;
}