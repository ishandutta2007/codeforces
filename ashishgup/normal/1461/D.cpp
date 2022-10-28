#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n, q;
int a[N], pref[N];
set<int> s;

void recurse(int l, int r)
{
	int sum = pref[r] - pref[l - 1];
	s.insert(sum);
	if(l == r)
		return;
	int mn = a[l], mx = a[r];
	int mid = (mn + mx) / 2;
	auto ub = upper_bound(a + l, a + r + 1, mid) - a;
	if(ub > l && ub != r + 1)
		recurse(l, ub - 1);
	if(ub <= r && ub != l)
		recurse(ub, r);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		s.clear();
		cin >> n >> q;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++)
			pref[i] = pref[i - 1] + a[i];
		recurse(1, n);
		while(q--)
		{
			int reqd;
			cin >> reqd;
			if(s.find(reqd) != s.end())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}