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
		ll a, b; cin >> a >> b;
		if (a == b) cout << "0\n";
		else if (a > b)
		{
			if (a % 2 == b % 2) cout << "1\n";
			else cout << "2\n";
		}
		else
		{
			if (a % 2 != b % 2) cout << "1\n";
			else cout << "2\n";
		}
	}
}