#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=5e5;
int a[N],b[N];
signed main()
{
//	freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n; 
		cin>>n;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) b[i]=a[i];
		sort(a+1,a+n+1);
		bool tt=0;
		rep(i,1,n) if (a[i]!=b[i]) tt=1;
		if (tt) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0; 
}