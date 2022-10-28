#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string a, b;

int32_t main()
{
	IOS;
	cin>>a>>b;
	int ans=a.size() + b.size();
	while(a.size() && b.size() && a.back()==b.back())
	{
		ans-=2;
		a.pop_back();
		b.pop_back();
	}
	cout<<ans;
	return 0;
}