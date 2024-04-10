#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	if (sum <= 1)
	{
		cout << "-1";
		return 0;
	}

	vector <int> div;
	for (int i = 2; i <= sum; i++)
	{
		if (sum % i == 0)
		{
			div.push_back(i);
		}
	}

	ll ans = numeric_limits<ll>::max();

	int cSum = 0;
	vector <int> v;

	for (int md : div)
	{
		ll res = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1)
			{
				v.push_back(i);
				cSum++;

				if (cSum == md)
				{
					ll mid = v[v.size() / 2];
					for (auto it : v)
					{
						ll tmp = it - mid;
						if (tmp < 0) tmp = -tmp;
						res += tmp;
					}

					v.clear();
					cSum = 0;
				}
			}
		}

		ans = min(ans, res);
	}
	

	cout << ans;
}