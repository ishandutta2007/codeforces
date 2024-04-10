#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
const ll N=2e6;
ll n,r1,r2,r3,d;
ll a[N];
ll f[N][2];
int main()
{
	ios::sync_with_stdio(false);
    cin>>n>>r1>>r2>>r3>>d;
    rep(i,1,n) cin>>a[i];
    f[0][0]=-d; f[0][1]=1e18;
    rep(i,1,n)
    {
    	f[i][0]=f[i-1][0]+d+min(r1,r3)*a[i]+r3;
    	if (i==n)
          f[i][0]=min(f[i][0],f[i-1][1]+min(r1,r3)*a[i]+r3);
    	f[i][0]=min(f[i][0],f[i-1][1]+d+min((a[i]+1)*r1,r2)+min(min(r1,r2),r3));
    	f[i][1]=f[i-1][0]+d+min((a[i]+1)*r1,r2)+min(min(r1,r2),r3)+2*d;
    	f[i][0]=min(f[i][0],f[i][1]);
    }
    cout<<min(f[n][0],f[n][1]);
	return 0; 
}