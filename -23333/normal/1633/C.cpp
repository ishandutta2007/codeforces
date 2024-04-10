#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
const int N=1e6;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		ll hc,dc,hm,dm,k,w,a;
		cin>>hc>>dc>>hm>>dm>>k>>w>>a;
		bool tt=0;
		rep(i,0,k)
		{
			if ((hm-1)/(dc+i*w)+1<=(hc+(k-i)*a-1)/dm+1) tt=1;
		}
		if (tt) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
	return 0;
}