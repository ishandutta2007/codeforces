#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, m;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		set<int> s;
		n /= m;
		int cur = m;
		int last = cur % 10;
		int sum = 0;
		while(n > 0 && s.find(cur % 10) == s.end())
		{
			s.insert(cur % 10);
			n--;
			sum += cur % 10;
			last = cur % 10;
			cur += m;
		}
		if(n == 0)
			cout << sum << endl;
		else
		{
			int ans = 0;
			ans += (n / s.size() + 1) * sum;
			n %= s.size();
			int cur = 0;
			for(int i = 1; i <= n; i++)
			{
				cur += m;
				ans += (cur % 10);
				cur %= 10;
			}
			cout << ans << endl;
		}

	}
	return 0;
}