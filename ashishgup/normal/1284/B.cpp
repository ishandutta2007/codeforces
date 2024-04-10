#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, valid = 0;
int mn[N], mx[N];
vector<int> mnn, mxx;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mn[i] = 1e9;
		int check = 0;
		int cur = 1e9;
		for(int j = 1; j <= x; j++)
		{
			int val;
			cin >> val;
			if(val > mn[i])
				check = 1;
			mn[i] = min(mn[i], val);
			mx[i] = max(mx[i], val);
		}
		if(check)
			valid++;
		else
			mnn.push_back(mn[i]), mxx.push_back(mx[i]);
	}
	sort(mxx.begin(), mxx.end());
	int ans = valid * valid + 2 * valid * (n - valid);
	for(auto &it:mnn)
	{
		auto x = mxx.end() - lower_bound(mxx.begin(), mxx.end(), it + 1);
		ans += x;
	}
	cout << ans << endl;
	return 0;
}