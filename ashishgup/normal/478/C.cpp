#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int r, g, b;

int32_t main()
{
	IOS;
	cin>>r>>g>>b;
	vector<int> v={r, g, b};
	sort(v.begin(), v.end());
	int ans=min((v[0]+v[1]+v[2])/3, v[0]+v[1]);
	cout<<ans;
	return 0;
}