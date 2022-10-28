#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, q;
int s[N], diff[N], pref[N];
set<int> distinct;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		distinct.insert(s[i]);
	}
	int have = distinct.size();
	sort(s + 1, s + n + 1);
	for(int i = 2; i <= n; i++)
		diff[i - 1] = max(0LL, (s[i] - s[i - 1] - 1));
	sort(diff + 1, diff + n);
	for(int i = 1; i <= n - 1; i++)
		pref[i] = pref[i - 1] + diff[i];
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		int gap = r - l;
		auto it = lower_bound(diff + 1, diff + n, gap) - diff;
		int extra = pref[it - 1] + (n - it) * gap;
		int ans = extra + have + gap;
		cout << ans << " ";
	}
	return 0;
}