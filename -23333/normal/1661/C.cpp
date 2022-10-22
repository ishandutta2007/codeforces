//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5+10;
const int mo=1e9+7;
int n,a[N],b[N],f[N];
ll check(int x)
{
	ll cnt1=0,cnt2=0;
	rep(i,1,n)
	{
	  cnt2+=(x-a[i])/2;
	  cnt1+=(x-a[i])%2;
    }
    for (ll kk=1ll*32768*32768*32768*8;kk>0;kk=kk/2)
    {
       if (cnt2-kk>=cnt1+kk*2-1) cnt2-=kk,cnt1+=kk*2;
    }
    if (cnt2>=cnt1) return 2*cnt2;
    return cnt1*2-1;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		int mx=0;
		rep(i,1,n) cin>>a[i],mx=max(mx,a[i]);
		cout<<min(check(mx),check(mx+1))<<endl;
	}
	return 0;
}