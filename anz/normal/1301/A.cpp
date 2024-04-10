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
		string a, b, c; cin >> a >> b >> c;

		bool ans = true;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != c[i] && b[i] != c[i]) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}