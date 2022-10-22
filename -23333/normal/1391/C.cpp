#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define ll long long
const int mo=1e9+7;
int main()
{
	int n;
	cin>>n;
	ll ans=1,ans2=1;
	rep(i,1,n-1) ans=ans*2%mo;
	rep(i,1,n) ans2=ans2*i%mo;
	cout<<(ans2-ans+mo)%mo<<endl;
	return 0;
}