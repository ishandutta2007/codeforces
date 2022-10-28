#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	vector<int> v;
	for(int i=0;i<3;i++)
	{
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int ans=v[2] + 1 - (v[1]+v[0]);
	ans=max(0LL, ans);
	cout<<ans;
	return 0;
}