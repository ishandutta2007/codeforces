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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int n;
		string s;
		cin >> n >> s;
		int ans = n;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				int tmp = max((i + 1) * 2, (n - i) * 2);
				ans = max(ans, tmp);
			}
		}

		cout << ans << "\n";
	}
}