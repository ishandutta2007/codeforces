#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, q;
int a[N], last[N];

int32_t main()
{
	IOS;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		last[a[i]] = i;
	}
	int mx = 0, ans = 0, cnt = 0;
	map<int, int> m;
	multiset<int> s;
	for(int i = 1; i <= n; i++)
	{
		if(i > mx)
		{
			if(cnt > 0)
				ans += (cnt - *s.rbegin());
			m.clear();
			s.clear();
			cnt = 0;
		}
		mx = max(mx, last[a[i]]);
		cnt++;
		if(m[a[i]])
			s.erase(s.find(m[a[i]]));
		m[a[i]]++;
			s.insert(m[a[i]]);
	}
	ans += (cnt - *s.rbegin());
	cout << ans;
	return 0;
}