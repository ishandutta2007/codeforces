#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector <int> x[1001];
		for (int i = 0; i < n; i++)
		{
			int a, b; cin >> a >> b;
			x[a].push_back(b);
		}

		bool isOk = true;
		string ans;

		int curY = 0;
		int cnt = 0;
		for (int i = 0; i <= 1000; i++) sort(x[i].begin(), x[i].end());
		for (int i = 0; i <= 1000; i++)
		{
			if (x[i].empty())
			{
				ans += 'R';
				continue;
			}
			if (x[i].front() < curY)
			{
				isOk = false;
				break;
			}

			for (int j = curY; j < x[i].back(); j++) ans += 'U';
			curY = x[i].back();
			cnt += x[i].size();

			if (cnt == n) break;
			ans += 'R';
		}

		if (!isOk)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		cout << ans << '\n';
	}
}