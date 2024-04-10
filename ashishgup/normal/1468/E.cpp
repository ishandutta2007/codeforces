#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		vector<int> v;
		for(int i = 1; i <= 4; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		do
		{
			int l = min(v[0], v[1]);
			int b = min(v[2], v[3]);
			ans = max(ans, l * b);
		}while(next_permutation(v.begin(), v.end()));
		cout << ans << endl;
	}
	return 0;
}