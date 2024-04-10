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
#include <ctime>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[501];

int dp[501][501];

int solve(int l, int r)
{
	int& ret = dp[l][r];
	if (ret != -1) return ret;
	if (l == r) return ret = a[l];
	if (r - l == 1)
	{
		if (a[l] == a[r]) return ret = a[l] + 1;
		else return ret = 0;
	}

	for (int i = l; i < r; i++)
	{
		int lres = solve(l, i);
		int rres = solve(i + 1, r);

		if (lres == 0 || rres == 0) continue;
		if (lres == rres) return ret = lres + 1;
	}

	return ret = 0;
}

int dp2[501][501];
int solve2(int l, int r)
{
	int& ret = dp2[l][r];
	if (ret != -1) return ret;
	if (dp[l][r]) return ret = 1;

	ret = 987654321;
	for (int i = l; i < r; i++)
	{
		ret = min(ret, solve2(l, i) + solve2(i + 1, r));
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	memset(dp, -1, sizeof dp);
	solve(0, n - 1);

	memset(dp2, -1, sizeof dp2);
	cout << solve2(0, n - 1);
}