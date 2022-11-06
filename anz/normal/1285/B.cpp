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
#include <list>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		priority_queue<pll> mx;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] += a[i - 1];
			mx.push({ a[i],i });
		}
		
		ll total = a[n];
		bool ans = true;

		for (int i = 1; i < n; i++)
		{
			if (a[i] >= total)
			{
				cout << "NO" << '\n';
				ans = false;
				break;
			}
		}

		if (!ans) continue;
		for (int i = 2; i <= n; i++)
		{
			ll cPsum = a[i-1];

			while (!mx.empty() && mx.top().second < i) mx.pop();
			if (mx.empty()) break;
			ll curMax = mx.top().first;

			if (curMax - cPsum >= total)
			{
				ans = false;
				break;
			}
		}
		
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}