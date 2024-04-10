#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6;
int n,m;
char s[N];
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		int mn=1e9,mx=0;
		rep(i,1,n) cin>>a[i];
		int cnt=0;
		rep(i,1,n-1)
		{
			if (a[i]==a[i+1]) mn=min(mn,i+1),mx=max(mx,i);
			if (a[i]==a[i+1]) cnt++;
		}
		if (cnt<=1) cout<<0<<endl;
		else cout<<max(1,mx-mn)<<endl;
	}
	return 0;
}