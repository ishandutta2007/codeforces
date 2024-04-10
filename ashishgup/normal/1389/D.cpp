#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int l1, r1, l2, r2;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> l1 >> r1 >> l2 >> r2;
		if(l1 > l2)
			swap(r1, r2), swap(l1, l2);
		int cur = max(0LL, min(r1, r2) - l2);
		int inter = cur;
		cur *= n;
		k -= cur;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(k <= 0)
				break;
			int reqd = min(k, max(r2, r1) - min(l1, l2) - inter);
			int cost = max(0LL, l2 - r1) + reqd;
			bool flag = 1;
			if(i >= 2)
				cost = min(cost, reqd * 2);
			ans += cost;
			k -= reqd;
		}
		if(k >= 0)
			ans += k * 2;
		cout << ans << endl;
	}
	return 0;
}