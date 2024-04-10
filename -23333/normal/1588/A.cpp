#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6;
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		bool tt=1;
		rep(i,1,n) if (b[i]!=a[i]&&b[i]!=a[i]+1) tt=0;
		if (tt) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
}