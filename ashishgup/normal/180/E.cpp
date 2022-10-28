#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m, k, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	set<pair<int, int> > s;
	for(int i = 1; i <= n; i++)
		s.insert({0, a[i]});
	map<int, int> f;
	int l = 1;
	for(int r = 1; r <= n; r++)
	{
		s.erase({f[a[r]], a[r]});
		f[a[r]]++;
		s.insert({f[a[r]], r});
		while(r - l + 1 - k > s.rbegin() -> first)
		{
			s.erase({f[a[l]], a[l]});
			f[a[l]]--;
			l++;
			s.insert({f[a[l]], a[l]});
		}
		ans = max(ans, s.rbegin() -> first);
	}
	cout << ans;
	return 0;
}