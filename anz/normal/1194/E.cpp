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

int n;
vector <pair <int, pii> > row, col;

bitset <5001> st[2501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			if (y1 > y2) swap(y1, y2);
			row.push_back({ x1,{y1,y2} });
		}
		else
		{
			if (x1 > x2) swap(x1, x2);
			col.push_back({ y1,{x1,x2} });
		}
	}

	if (row.size() > col.size()) swap(row, col);

	sort(row.begin(), row.end());

	for (int i = 0; i < row.size(); i++) for (int j = 0; j < col.size(); j++)
	{
		if (row[i].second.first <= col[j].first && col[j].first <= row[i].second.second &&
			col[j].second.first <= row[i].first && row[i].first <= col[j].second.second)
			st[i].set(j);
	}

	ll ans = 0;

	for (int i = 0; i < row.size(); i++) for (int j = i + 1; j < row.size(); j++)
	{
		ll tmp = (st[i] & st[j]).count();
		tmp *= tmp - 1;
		tmp /= 2;
		ans += tmp;
	}

	cout << ans;
}