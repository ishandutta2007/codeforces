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
		int a, b, c; cin >> a >> b >> c;
		
		int ans = 0;
		while (b >= 1 && c >= 2)
		{
			ans += 3;
			b -= 1;
			c -= 2;
		}
		while (a >= 1 && b >= 2)
		{
			ans+=3;
			a -= 1;
			b -= 2;
		}

		cout << ans << "\n";
	}
}