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
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int l, r; cin >> l >> r;
	for (int i = l; i <= r; i++)
	{
		vector <int> d;
		int num = i;
		while (num)
		{
			d.push_back(num % 10);
			num /= 10;
		}
		sort(d.begin(), d.end());
		bool flag = true;
		for (int j = 0; j < d.size() - 1; j++)
		{
			if (d[j] == d[j + 1]) flag = false;
		}

		if (flag)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
}