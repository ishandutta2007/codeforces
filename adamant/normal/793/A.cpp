#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	set<int> rem;
	multiset<int> dv;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		rem.insert(a[i] % k);
		dv.insert(a[i] / k);
	}
	if(rem.size() > 1)
	{
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for(auto it: dv)
		ans += it - *begin(dv);
	cout << ans << endl;
		
	return 0;
}