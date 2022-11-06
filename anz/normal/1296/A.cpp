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
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (a % 2) odd++;
			else even++;
		}

		if (odd % 2) cout << "YES\n";
		else
		{
			if (odd && even) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}