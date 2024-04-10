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
	vector<pair<int, int> > v;
	int sum = 0, cur = 2, cnt = 1;
	while(sum <= 1e18)
	{
		sum += cur * (cur - 1) / 2;
		v.push_back({sum, cnt});
		cur *= 2;
		cnt++;
	}
	while(t--)
	{
		int x;
		cin >> x;
		pair<int, int> p = {x, 1e9};
		int ans = upper_bound(v.begin(), v.end(), p) - v.begin() - 1;
		cout << v[ans].second << endl;
	}
	return 0;
}