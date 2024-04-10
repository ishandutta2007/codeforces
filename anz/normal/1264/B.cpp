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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int a, b, c, d; cin >> a >> b >> c >> d;

	deque <int> ans;
	if (a <= b)
	{
		for (int i = 0; i < a; i++)
		{
			ans.push_back(0);
			ans.push_back(1);
		}

		b -= a; a = 0;

		if (b <= c)
		{
			for (int i = 0; i < b; i++)
			{
				ans.push_back(2);
				ans.push_back(1);
			}

			c -= b; b = 0;

			if (c == d + 1)
			{
				for (int i = 0; i < d; i++)
				{
					ans.push_back(2);
					ans.push_back(3);
				}
				ans.push_back(2);
			}
			else if (c == d)
			{
				for (int i = 0; i < d; i++)
				{
					ans.push_back(2);
					ans.push_back(3);
				}
			}
			else if (c + 1 == d)
			{
				if (!ans.empty() && ans.back() == 1 && ans.front() != 1)
				{
					ans.pop_back();
					ans.push_front(1);

					if (ans.back() == 2)
					{
						for (int i = 0; i < c; i++)
						{
							ans.push_back(3);
							ans.push_back(2);
						}
						ans.push_back(3);
					}
					else
					{
						cout << "NO";
						return 0;
					}
				}
				else if (ans.empty())
				{
					for (int i = 0; i < c; i++)
					{
						ans.push_back(3);
						ans.push_back(2);
					}
					ans.push_back(3);
				}
				else
				{
					cout << "NO";
					return 0;
				}
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else if (b == c + 1)
		{
			if (d == 0)
			{
				ans.push_front(1);
				for (int i = 0; i < c; i++)
				{
					ans.push_back(2);
					ans.push_back(1);
				}
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	else if (a == b + 1)
	{
		if (c == 0 && d == 0)
		{
			for (int i = 0; i < b; i++)
			{
				ans.push_back(0);
				ans.push_back(1);
			}
			ans.push_back(0);
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	else
	{
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (auto it : ans) cout << it << ' ';
}