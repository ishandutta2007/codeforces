#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], pref[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	int last = 0, ans = 0;
	map<int, int> idx;
	idx[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(idx.count(pref[i]))
			last = max(last, idx[pref[i]] + 1);
		ans += max(0LL, i - last);
		idx[pref[i]] = i;
	}
	cout << ans;
	return 0;
}