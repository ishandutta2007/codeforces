#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1005;
int n,m,q;
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
ll dp[N][N][2],a[N][N];
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	rep(i,1,n)
	  rep(j,1,m) dp[i][j][0]=dp[i][j][1]=1;// 0 xia 1 you
	ll ans=0;
	rep(i,1,n)
	  rep(j,1,m)
	  {
	    dp[i][j][1]+=dp[i-1][j][0];
	    dp[i][j][0]+=dp[i][j-1][1];
	    ans+=dp[i][j][1]+dp[i][j][0];
	  }
	rep(i,0,n+1)
	  rep(j,0,m+1)
	    if (i==0||i==n+1||j==0||j==m+1) a[i][j]=1;
	ans-=n*m;
	rep(i,1,q)
	{
		int x,y;
		cin>>x>>y;
		ll tt=1;
		if (!a[x][y]) tt=-1;
		a[x][y]^=1;
		ll an1=1,an2=1,an3=1,an4=1;
		ll now=0;
		int X=x,Y=y;
		while (1)
		{
			if (!now) X--; else Y--;
			now^=1;
			if (a[X][Y]) break;
			an1++;
		}
		
		now=1;
		X=x,Y=y;
		while (1)
		{
			if (!now) X--; else Y--;
			now^=1;
			if (a[X][Y]) break;
			an2++;
		}
		
		now=0;
		X=x,Y=y;
		while (1)
		{
			if (!now) X++; else Y++;
			now^=1;
			if (a[X][Y]) break;
			an3++;
		}
		
		now=1;
		X=x,Y=y;
		while (1)
		{
			if (!now) X++; else Y++;
			now^=1;
			if (a[X][Y]) break;
			an4++;
		}
		
		ans+=tt*(an1*an4+an2*an3-1); 
		cout<<ans<<endl; 
	}
	return 0;
}