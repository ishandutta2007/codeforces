#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, r;
int l[N], t[N];

int32_t main()
{
	IOS;
	cin >> n >> r;
	for(int i = 1; i <= n; i++)
		cin >> l[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> t[i];
		if(l[i] > t[i])
		{
			cout << "-1";
			return 0;
		}
	}
	int prev = 0, timer = 0, ans = 0;
	vector<int> v;
	for(int i = 1; i <= n; i++)
	{
		int cur = min(prev, l[i]);
		prev -= cur;
		l[i] -= cur;
		t[i] -= cur;
		if(l[i] * 2 <= t[i])
		{
			timer += l[i] * 2;
			continue;
		}
		int lo = 0, hi = l[i];
		while(lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if(l[i] - mid <= t[i] - mid * 2)
				lo = mid;
			else
				hi = mid - 1;
		}
		l[i] -= lo;
		timer += lo * 2;
		int jumps = (l[i] + r - 1) / r;
		ans += jumps;
		prev = jumps * r - l[i];
		while(v.size() < 1e5 && jumps > 0)
		{
			jumps--;
			v.push_back(timer);
			timer += r;
		}
	}
	cout << ans << endl;
	if(ans <= 1e5)
	{
		for(auto &it:v)
			cout << it << " ";
	}
	return 0;
}