#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long

int n, ans=0;
vector<int> v={100, 20, 10, 5, 1};

int32_t main()
{
	IOS;
	cin>>n;
	for(auto it:v)
	{
		int cur=n/it;
		n-=cur*it;
		ans+=cur;
	}
	cout<<ans;
}