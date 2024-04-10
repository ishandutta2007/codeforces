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
		cin>>s;
		int n=strlen(s);
		int cnt0=0,cnt1=0;
		rep(i,0,n-1)
		  if (s[i]=='0') cnt0++; else cnt1++;
		int ans=min(cnt0,cnt1);
		if (cnt0==cnt1) ans--;
		cout<<ans<<endl;
	}
	return 0;
}