#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, a, b;
int x[N];

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		int maxget=(x[i]*a)/b;
		int taken=(maxget*b+a-1)/a;
		int ans=x[i]-taken;
		cout<<ans<<" ";
	}
	return 0;
}