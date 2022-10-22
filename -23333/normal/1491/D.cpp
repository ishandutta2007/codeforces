#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
const int N=2e5;
int f[N],g[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{ 
	int x,y;
	   cin>>x>>y;
	   int cnt=0,cnt1=0;
	   rep(i,1,30)
	     if((x>>(i-1))&1) f[++cnt]=i;
	   rep(i,1,30)
	     if ((y>>(i-1))&1) g[++cnt1]=i;
	   int now=1;
	   bool tt=1;
	   if (cnt<cnt1||x>y) tt=0;
	   rep(i,1,cnt1) if (f[i]>g[i]) tt=0;
       if (tt) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
	return 0;
}