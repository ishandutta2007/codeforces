#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=2e6;
int a[N],b[N];
const int mo=1e9+7;
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
ll fsp(int x,int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    ll ans=fsp(x,y/2);
    ans=ans*ans;
    if (ans>1e9) ans=1e9;
    if (y%2==1) ans=ans*x;
    if (ans>1e9) ans=1e9;
    return ans; 
}
int h[5][50];
bool check(int x,int y)
{
	while (x||y)
	{
		int t1=x%2,t2=y%2;
		if (t1==0&&t2==1) return 0;
		x/=2,y/=2;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
    int gg=(1<<20)-1;
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(j,0,2)
	  rep(i,0,22)
	  {
		int nn=n-1-i-j;
		int gg=0;
		rep(k,max(0,m-j),nn)
		  gg^=check(nn,k);
		h[j][i]=gg;
	  }
	rep(i,1,n)
	{
	  ll now=a[i];
	  rep(j,i,min(n,i+21))
	  {
	  	//ll now=a[i];
	  	if (j!=i)
	  	{
	  		now=now*fsp(2,a[j]);
	  		if (now>1e9) now=1e9; 
	  	}
	  	if (now>=1e9) break;
	  	int cnt=0;
	  	if (i!=1) cnt++;
	  	if (j!=n) cnt++;
	  	if (now<=gg) b[now]^=h[cnt][j-i];
	  }
    }
	int now=0;
	rep(i,0,gg)
	  if (b[i]!=0) now=i;
	dep(i,now,0) cout<<b[i];
	return 0;
}
/*
1
-9 3 11
0 6 3
*/