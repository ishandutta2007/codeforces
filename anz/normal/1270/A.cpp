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
		int n, k1, k2; cin >> n >> k1 >> k2;
		
		int max1 = 0, max2 = 0;
		for (int i = 0; i < k1; i++)
		{
			int t; cin >> t;
			max1 = max(max1, t);
		}
		for (int i = 0; i < k2; i++)
		{
			int t; cin >> t;
			max2 = max(max2, t);
		}

		if (max1 > max2) cout << "YES\n";
		else cout << "NO\n";
	}
}