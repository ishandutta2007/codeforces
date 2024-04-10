#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int w, h, n;
set<int> rows, cols;
multiset<int> rgaps, cgaps;

int32_t main()
{
	IOS;
	cin >> w >> h >> n;
	rows.insert(0);
	rows.insert(w);
	cols.insert(0);
	cols.insert(h);
	rgaps.insert(w);
	cgaps.insert(h);
	for(int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		if(ch == 'V')
		{
			int x;
			cin >> x;
			x = w - x;
			auto it = rows.lower_bound(x);
			int up = *it;
			int low = *(--it);
			rgaps.erase(rgaps.find(up - low));
			rgaps.insert(x - low);
			rgaps.insert(up - x);
			rows.insert(x);
		}
		else
		{
			int x;
			cin >> x;
			x = h - x;
			auto it = cols.lower_bound(x);
			int up = *it;
			int low = *(--it);
			cgaps.erase(cgaps.find(up - low));
			cgaps.insert(x - low);
			cgaps.insert(up - x);
			cols.insert(x);
		}
		int ans = *rgaps.rbegin();
		ans *= *cgaps.rbegin();
		cout << ans << endl;
	}
	return 0;
}