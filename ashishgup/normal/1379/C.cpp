#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

struct data
{
	int a, b;
};

int n, m;
data d[N];

bool comp(data &d1, data &d2)
{
	return d1.b < d2.b;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
			cin >> d[i].a >> d[i].b;
		sort(d + 1, d + m + 1, comp);
		int sum = 0, ans = 0;
		multiset<int> s;
		for(int i = 1; i <= m; i++)
		{
			while(s.size() && (*s.begin() < d[i].b || s.size() >= n))
			{
				sum -= *s.begin();
				s.erase(s.begin());
			}
			int cur = sum + d[i].a;
			int rem = n - s.size() - 1;
			cur += rem * d[i].b;
			ans = max(ans, cur);
			s.insert(d[i].a);
			sum += d[i].a;
		}
		cout << ans << endl;
	}
	return 0;
}