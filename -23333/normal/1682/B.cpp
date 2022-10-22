#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=3e5;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		int ans=(1<<30)-1;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) 
		  if (a[i]!=i-1) ans&=a[i];
		cout<<ans<<endl;
	}
	return 0;
}