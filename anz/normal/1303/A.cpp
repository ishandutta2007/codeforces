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

string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> s;
		int l = 0, r = s.size() - 1;
		while (l < s.size() && s[l] == '0') l++;
		while (r >= l && s[r] == '0') r--;

		int ans = 0;
		for (int i = l; i <= r; i++)
		{
			if (s[i] == '0') ans++;
		}
		cout << ans << '\n';
	}
}