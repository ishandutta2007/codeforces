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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

ll n;
ll stone[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> stone[i];
	sort(stone, stone + n);

	ll same = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (stone[i] == stone[i + 1])
		{
			if (stone[i] == 0)
			{
				cout << "cslnb";
				return 0;
			}
			if (i > 0 && stone[i - 1] + 1 == stone[i])
			{
				cout << "cslnb";
				return 0;
			}
			same++;
		}
	}

	if (same > 1)
	{
		cout << "cslnb";
		return 0;
	}

	ll remain = 0;
	for (int i = 0; i < n; i++) remain += stone[i] - i;
	if (remain % 2 == 0) cout << "cslnb";
	else cout << "sjfnb";
}