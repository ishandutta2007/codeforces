#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++) 
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int t;
const int N=3005;
ll a[N],sum[N][N];
void change(int h1,int h2,int t1,int t2)
{
	sum[h1][t1]++; sum[h1][t2+1]--; sum[h2+1][t1]--; sum[h2+1][t2+1]++;
}
int main()
{
	int T;
	cin>>T;
	rep(i,1,T)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>a[i];
		rep(i,2,n)
		  rep(j,i+2,n)
		    if (a[i]==a[j])
		    {
		    	change(1,i-1,i+1,j-1);
		    }
		rep(i,1,n)
		  rep(j,1,n) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		ll ans=0;
		rep(i,1,n)
		  rep(j,i+2,n)
		    if (a[i]==a[j])
		      ans+=sum[i][j];
		cout<<ans<<endl;
		rep(i,1,n)
		  rep(j,1,n) sum[i][j]=0;
	}
	return 0; 
}