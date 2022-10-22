#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=3e5+10;
int a[N],T,n;
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	rep(i,1,T)
	{
		cin>>n;
		rep(i,1,n) cin>>a[i];
		bool t=1;
		rep(i,2,n) if (a[i]!=a[i-1]) t=0;
		if (t==1) cout<<n<<endl; else cout<<1<<endl; 
	}
	return 0;
}