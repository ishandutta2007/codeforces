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

	int T; cin >> T;
	while (T--)
	{
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		int cnt = 0;
		while (a != b)
		{
			if (a + 5 <= b)
			{
				int t = (b - a) / 5;
				a += t * 5;
				cnt += t;
			}
			else if (a + 2 <= b) a += 2, cnt++;
			else a++, cnt++;
		}
		cout << cnt << '\n';
	}
}