#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll n,m;
const int N=1e6;
int a[N];
ll sum[N];
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		rep(i,1,n) cin>>a[i];
		sort(a+1,a+n+1);
		rep(i,1,n) sum[i]=sum[i-1]+a[i];
		bool tt=0;
		rep(i,1,(n+1)/2-1)
		{
			if (sum[i+1]<sum[n]-sum[n-i]) tt=1;
		}
		if (tt) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}