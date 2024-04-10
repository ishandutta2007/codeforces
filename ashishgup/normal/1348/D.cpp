#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int have = 1, rem = n - 1;
		vector<int> ans;
		while(rem >= 0)
		{
			if(have * 2 >= rem)
			{
				ans.push_back(rem - have);
				break;
			}
			int x = min(rem / 2 - have, have);
			ans.push_back(x);
			have += x;
			rem -= have;
		}
		cout << ans.size() << endl;
		for(auto &it:ans)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}