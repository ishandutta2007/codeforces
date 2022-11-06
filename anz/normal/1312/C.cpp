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
#include <complex>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
int cnt[100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);

		bool ans = true;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			ll a; cin >> a;

			int idx = 0;
			while (a)
			{
				if (a % k == 1)
				{
					cnt[idx]++;
				}
				else if (a % k > 0)
				{
					ans = false;
				}

				a /= k;
				idx++;
			}
		}

		for (int i = 0; i < 100; i++)
		{
			if (cnt[i] > 1)
			{
				ans = false;
				break;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}