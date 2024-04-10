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

	int t; cin >> t;
	while (t--)
	{
		ll n, x; cin >> n >> x;
		string s; cin >> s;
		
		map <ll, int> bal;
		int cb = 0;
		for (int i = 0; i < s.size(); i++)
		{
			bal[cb]++;
			if (s[i] == '0') cb++;
			else cb--;
		}

		ll ans = 0;
		if (cb == 0)
		{
			if (bal[x] == 0) cout << "0\n";
			else cout << "-1\n";
			continue;
		}

		for (auto& it : bal)
		{
			ll num = it.first;
			if (cb > 0 && num > x || cb < 0 && num < x) continue;
			if ((x - num) % cb == 0) ans += it.second;
		}
		cout << ans << '\n';
	}
}