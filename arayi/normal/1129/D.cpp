#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 1e5 + 500;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 250;

lli bp(lli a, lli b = mod - 2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

int n, k;
lli a[N], dp[N];
lli col[N], b[N], sum[4 * T], q[6 * T][6 * T];
vector <int> verj[N];
void upd(int i1)
{
	while (i1 < n && col[i1 + 1] == col[i1]) i1++;
	//cout << i1 << endl;
	int sm = b[i1];
	int ss = col[i1];
	for (int i = 0; i <= 2 * T; i++)
	{
		q[ss][i] = 0;
	}
	q[ss][sm + T] += dp[i1 - 1];
	q[ss][sm + T] %= mod;
	while (i1 > 1 && col[i1] == col[i1 - 1])
	{
		i1--;
		sm += b[i1];
		q[ss][sm + T] += dp[i1 - 1];
		q[ss][sm + T] %= mod;
	}
	for (int i = 1; i <= 2 * T; i++)
	{
		q[ss][i] += q[ss][i - 1];
		q[ss][i] %= mod;
	}
	sum[ss] = sm;
}
int main()
{
	fastio;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i += T)
	{
		for (int j = 0; j < T; j++)
		{
			col[i + j] = i / T + 1;
		}
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (verj[a[i]].size() >= 2) b[verj[a[i]][verj[a[i]].size() - 2]] = 0, upd(verj[a[i]][verj[a[i]].size() - 2]);
		if (verj[a[i]].size() >= 1) b[verj[a[i]].back()] = -1, upd(verj[a[i]].back());
		verj[a[i]].PB(i); b[i] = 1;
		upd(i);
		int sm = 0, ss = col[i];
		int i1 = i;
		//cout << i << " " << ss << " ";
		while (i1 > 0 && col[i1] == ss)
		{
			sm += b[i1];
			if (sm <= k) dp[i] += dp[i1 - 1], dp[i] %= mod;
			i1--;
		}
		//cout << dp[i] << " ";
		for (int j = ss - 1; j > 0; j--)
		{
			if (k - sm + T >= 0) dp[i] += q[j][min(2 * T, k - sm + T)], dp[i] %= mod;
			sm += sum[j];
		}
		//cout << dp[i] << endl;
	}
	cout << dp[n] << endl;
	return 0;
}
/*
  __
*(><)*
  \/ /
  ||/
--||
  ||
  /\
 /  \
/    \
*/