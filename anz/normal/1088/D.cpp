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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int ca[30], cb[30];
	memset(ca, -1, sizeof ca);
	memset(cb, -1, sizeof cb);

	int a = 0, b = 0;

	cout << "? 0 0" << endl;

	int flag;
	cin >> flag;

//	int ra = 18, rb = 511;

	for (int i = 29; i >= 0; i--)
	{
		int tmpa = (a | (1 << i));
		int tmpb = (b | (1 << i));

		int res1, res2;
		cout << "? " << tmpa << ' ' << b << endl;
//		cout << (ra^tmpa) << ' ' << (rb^b) << endl;
		cin >> res1;

		cout << "? " << a << ' ' << tmpb << endl;
//		cout << (ra^a) << ' ' << (rb^tmpb) << endl;
		cin >> res2;

		if (flag == 1)
		{
			if (res1 == 1)
			{
				if (res2 == 1)
				{
					a |= (1 << i);
				}
			}
			else if (res1 == -1)
			{
				if (res2 == 1)
				{
					a |= (1 << i);
					b |= (1 << i);
				}
				else if (res2 == -1)
				{
					a |= (1 << i);
					flag = -1;
				}
			}
			else
			{
				a |= (1 << i);
				flag = 0;
			}
		}
		else if (flag == -1)
		{
			if (res2 == 1)
			{
				if (res1 == 1)
				{
					b |= (1 << i);
					flag = 1;
				}
				else
				{
					a |= (1 << i);
					b |= (1 << i);
				}
			}
			else if (res2 == -1)
			{
				if (res1 == -1)
				{
					b |= (1 << i);
				}
			}
			else
			{
				b |= (1 << i);
				flag = 0;
			}
		}
		else
		{
			if (res1 == -1)
			{
				a |= (1 << i);
				b |= (1 << i);
			}
		}
	}

	cout << "! " << a << ' ' << b << endl;
}