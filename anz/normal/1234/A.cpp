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

	int q; cin >> q;
	while (q--)
	{
		int n; cin >> n;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			ll t; cin >> t;
			sum += t;
		}

		cout << (sum - 1) / n + 1 << "\n";
	}
}