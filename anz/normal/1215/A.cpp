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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int a1, a2, k1, k2;
	cin >> a1 >> a2 >> k1 >> k2;

	int n; cin >> n;
	if (k1 > k2)
	{
		swap(a1, a2);
		swap(k1, k2);
	}

	// now k1 <= k2
	int minAns = max(0, min(a1 + a2, n - (a1*(k1 - 1) + a2 * (k2 - 1))));

	int red1 = min(a1, n / k1);
	n -= red1 * k1;
	int red2 = min(a2, n / k2);
	int maxAns = red1 + red2;
	cout << minAns << ' ' << maxAns;
}