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

vector <ll> pr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	pr.push_back(2);
	for (ll i = 3; i*i <= 1000000000; i++)
	{
		bool flag = false;
		for (int j = 0; j < pr.size() && pr[j] * pr[j] <= i; j++)
		{
			if (i % pr[j] == 0)
			{
				flag = true;
				break;
			}
		}

		if (!flag) pr.push_back(i);
	}

	int t; cin >> t;
	while (t--)
	{
		map<ll, int> mp;
		ll n; cin >> n;
		for (int i = 0; i < pr.size(); i++)
		{
			while (n % pr[i] == 0)
			{
				n /= pr[i];
				mp[pr[i]]++;
			}
		}

		if (n != 1) mp[n]++;

		if (mp.size() >= 3)
		{
			cout << "YES\n";

			ll tmp = 1;
			int cnt = 0;
			for (auto &it : mp)
			{
				if (cnt < 3) tmp = 1;
				for (int i = 0; i < it.second; i++)
					tmp *= it.first;

				if (cnt < 2)
				{
					cout << tmp << ' ';
				}
				cnt++;
			}
			cout << tmp << ' ';
			cout << '\n';
		}
		else if (mp.size() == 2)
		{
			int twoCnt = 0;
			bool flag = false;
			for (auto &it : mp)
			{
				if (it.second >= 3)
					flag = true;
				else if (it.second == 2) twoCnt++;
			}

			if (!flag)
			{
				if (twoCnt == 2)
				{
					cout << "YES\n";
					ll f1 = (*mp.begin()).first;
					ll f2 = (*++mp.begin()).first;

					cout << f1 << ' ' << f2 << ' ' << f1 * f2 << '\n';
				}
				else cout << "NO\n";
				continue;
			}

			cout << "YES\n";
			bool hasPrinted = false;
			for (auto &it : mp)
			{
				if (it.second >= 3 && !hasPrinted)
				{
					cout << it.first << ' ';
					ll tmp = 1;
					for (int i = 0; i < it.second - 1; i++)
						tmp *= it.first;

					cout << tmp << ' ';
					hasPrinted = true;
				}
				else
				{
					ll tmp = 1;
					for (int i = 0; i < it.second; i++)
						tmp *= it.first;

					cout << tmp << ' ';
				}
			}
			cout << '\n';
		}
		else if (mp.size() == 1)
		{
			auto it = *mp.begin();
			if (it.second < 6)
			{
				cout << "NO\n";
				continue;
			}

			cout << "YES\n";
			ll num = it.first;
			cout << num << ' ' << num * num << ' ';

			ll tmp = 1;
			for (int i = 0; i < it.second - 3; i++)
				tmp *= it.first;
			cout << tmp << '\n';
		}
		else cout << "NO\n";
	}
}