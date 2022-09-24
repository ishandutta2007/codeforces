//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <array>
#include <string>
#include <set>
#include <map>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include <deque>

#define X first
#define Y second

using ll = long long;
using ld = long double;

using namespace std;


void solve()
{
	ll a, b, c, r, ans;
	cin >> a >> b >> c >> r;
	if (a > b)
	{
		swap(a, b);
	}
	if (c < a)
	{
		a = max(c + r, a);
		ans = b - a;
		if (ans < 0) ans = 0;
		cout << ans << endl;
		return;
	}
	if (c > b)
	{
		b = min(b, c - r);
		ans = b - a;
		if (ans < 0) ans = 0;
		cout << ans << endl;
		return;
	}
	ll delta = 2 * r;
	if (c - r < a)
	{
		a = c;
		delta -= r;
	}
	if (c + r > b)
	{
		b = c;
		delta -= r;
	}
	ans = b - a - delta;
	cout << ans << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
}