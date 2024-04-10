//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5+10;
const int mo=1e9+7;
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    int n;
	    cin>>n;
	    rep(i,1,n) cin>>a[i];
		rep(i,1,n) cin>>b[i];
	    rep(i,1,n) if (a[i]<b[i]) swap(a[i],b[i]);
	    ll ans=0;
	    rep(i,1,n-1) ans+=abs(a[i+1]-a[i])+abs(b[i+1]-b[i]);
	    cout<<ans<<endl; 
	}
	return 0;
}