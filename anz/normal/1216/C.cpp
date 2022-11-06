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

	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> x5 >> y5 >> x6 >> y6;

	if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2)
		cout << "NO";
	else if (x5 <= x1 && x6 >= x2 && y5 <= y1 && y6 >= y2)
		cout << "NO";
	else
	{
		if (x3 <= x1 && x4 >= x2 && x5 <= x1 && x6 >= x2)
		{
			if (y3 <= y1 && y6 >= y2 && y4 >= y5 ||
				y5 <= y1 && y4 >= y2 && y6 >= y3)
			{
				cout << "NO";
				return 0;
			}
		}

		if (y3 <= y1 && y4 >= y2 && y5 <= y1 && y6 >= y2)
		{
			if (x3 <= x1 && x6 >= x2 && x4 >= x5 ||
				x5 <= x1 && x4 >= x2 && x6 >= x3)
			{
				cout << "NO";
				return 0;
			}
		}

		cout << "YES";
	}
}