#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int mo=998244353;
const int N=1010;
ll jc[N],jc2[N];
ll dp[N][N];
ll fsp(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	ll ans=fsp(x,y/2);
	ans=ans*ans%mo;
	if (y%2==1) ans=ans*x%mo;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	jc[0]=jc2[0]=1;
	rep(i,1,1000) jc[i]=jc[i-1]*i%mo; jc2[1000]=fsp(jc[1000],mo-2);
	dep(i,999,1) jc2[i]=jc2[i+1]*(i+1)%mo;
	dp[0][0]=jc[n-1];
	rep(i,1,k)
	  rep(j,0,n-1)
	    rep(t,0,j)
	    {
	  	   (dp[i][j]+=dp[i-1][t]*jc2[j-t]%mo*fsp(k-i+1,(j-t)*(j-t-1)/2+(j-t)*t))%=mo;
	    }
	cout<<dp[k][n-1]<<endl;
	return 0;
}