#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n=5, h1, h2, ans=0;
int m[10], w[10];

int32_t main()
{
	IOS;
	for(int i=1;i<=n;i++)
		cin>>m[i];
	for(int i=1;i<=n;i++)
		cin>>w[i];
	cin>>h1>>h2;
	ans=100*h1 - 50*h2;
	for(int i=1;i<=n;i++)
	{
		ans+=max((3*i*500/10), i*500 - i*500*m[i]/250 - 50*w[i]);
	}
	cout<<ans;
	return 0;
}