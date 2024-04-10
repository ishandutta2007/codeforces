#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int ans=0;
		int n,m;
		cin>>n>>m;
		rep(i,1,n)
		{
			int x;
			cin>>x;
			ans=max(ans,x|m);
		}
		cout<<ans<<endl;
	}
	return 0;
}