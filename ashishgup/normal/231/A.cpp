#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		ans+=((a+b+c)>=2);
	}
	cout<<ans;
	return 0;   
}