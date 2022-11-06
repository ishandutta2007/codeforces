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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int n, d; cin >> n >> d;
		int sq = sqrt(d);

		bool ans = false;
		for (int i = max(0, sq - 5); i <= sq + 5; i++)
		{
			if (i + ceil((double)d / (i + 1)) <= n)
			{
				ans = true;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}