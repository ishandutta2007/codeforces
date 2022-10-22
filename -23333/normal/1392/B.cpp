#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
const ll N=3e5+10;
ll a[N],T,n;
ll m;
void sc()
{
	ll ans=-1e9;
	rep(i,1,n) ans=max(ans,a[i]);
	rep(i,1,n) a[i]=ans-a[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	rep(i,1,T)
	{
		cin>>n>>m;
		if (m>2) m=(m-2)%2+2;
		rep(i,1,n) cin>>a[i];
		rep(i,1,m) sc();
		rep(i,1,n) cout<<a[i]<<" ";
		cout<<endl; 
	}
	return 0;
}