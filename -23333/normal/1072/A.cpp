#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
int n,m,k;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	int ans=0;
	rep(i,1,k)
	{
		ans+=(n+m-2)*2;
		n-=4,m-=4;
	}
	cout<<ans<<endl;
	return 0;
}