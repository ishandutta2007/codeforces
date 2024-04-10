#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	rep(i,1,T)
	{
		int n,m;
		cin>>n>>m;
		if (m>=n) cout<<m-n<<endl;
		else if (m%2==n%2) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}