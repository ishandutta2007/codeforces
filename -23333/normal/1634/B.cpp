#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
int n,m;
const int N=1e6;
ll a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		ll n,x,y;
		cin>>n>>x>>y;
		rep(i,1,n) cin>>a[i];
		ll gg=0;
		rep(i,1,n) gg+=a[i];
		if ((x+gg)%2==y%2)
		{
			cout<<"Alice"<<endl;
		} else cout<<"Bob"<<endl; 
	}
	return 0;
}