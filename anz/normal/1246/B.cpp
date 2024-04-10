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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <ll> p;
ll n, k;
map <vector<ll>, ll > s;
map <pair<vector<ll>, ll>, ll> s2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	p.push_back(2);
	for (ll i = 3; i*i <= 100000; i++)
	{
		bool flag = true;
		for (int j = 0; j < p.size() && p[j] * p[j] <= i; j++)
		{
			if (i % p[j] == 0)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			ll c = i;
			bool flag = true;
			for (int z = 1; z < k; z++)
			{
				c *= i;
				if (c > 10000000000)
				{
					flag = false;
					break;
				}
			}
			if (!flag) break;
			p.push_back(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		ll t; cin >> t;
		vector <ll> cv;

		for (int j = 0; j < p.size(); j++)
		{
			ll cnt = 0;
			while (t % p[j] == 0)
			{
				t /= p[j];
				cnt++;
			}
			cv.push_back(cnt % k);
		}

		if (t == 1)
		{
			s[cv]++;
		}
		else if (k == 2)
		{
			s2[{cv, t}]++;
		}
	}

	ll ans = 0;
	for (auto it : s)
	{
		auto cv = it.first;
		ll num = it.second;

		vector <ll> fnd;
		for (auto i : cv)
		{
			fnd.push_back((k - i) % k);
		}

		if (cv == fnd)
		{
			ans += num * (num - 1);
			continue;
		}

		if (s.find(fnd) != s.end())
			ans += num * s[fnd];
	}

	for (auto it : s2)
	{
		auto cv = it.first.first;
		ll n2 = it.first.second;
		ll num = it.second;

		vector <ll> fnd;
		for (auto i : cv)
		{
			fnd.push_back((k - i) % k);
		}

		if (cv == fnd)
		{
			ans += num * (num - 1);
			continue;
		}

		if (s2.find({ fnd,n2 }) != s2.end())
			ans += num * s2[{fnd, n2}];
	}

	cout << ans / 2;
}