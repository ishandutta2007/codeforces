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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	int drink[1001] = { 0, };
	for (int i = 0; i < n; i++)
	{
		int t; cin >> t;
		drink[t]++;
	}

	int mx = (n + 1) / 2;

	int two = 0, one = 0;
	for (int i = 1; i <= k; i++)
	{
		two += drink[i] / 2;
		one += drink[i] % 2;
	}

	int ans = 0;
	if (two >= mx) ans = mx * 2;
	else
	{
		ans = two * 2 + (mx - two);
	}

	cout << ans;
}