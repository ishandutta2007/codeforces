#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int mx = 0;
		for(auto &it:s)
			mx = max((int)it - '0', mx);
		cout << mx << endl;
	}
	return 0;
}