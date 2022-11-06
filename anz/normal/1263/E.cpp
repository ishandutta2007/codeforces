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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 1000001;
const int INF = 987654321;

int n;

int a[N];
int st_sum[N * 4], st_max[N * 4], st_min[N * 4];
int lazy_sum[N * 4], lazy_max[N * 4], lazy_min[N * 4];

void sl_sum(int ptr, int l, int r)
{
	int tmp = lazy_sum[ptr];
	lazy_sum[ptr] = 0;
	st_sum[ptr] = tmp * (r - l + 1);
	if (l != r)
	{
		lazy_sum[ptr * 2] += tmp;
		lazy_sum[ptr * 2 + 1] += tmp;
	}
}

void sl_max(int ptr, int l, int r)
{
	int tmp = lazy_max[ptr];
	lazy_max[ptr] = 0;
	st_max[ptr] += tmp;
	if (l != r)
	{
		lazy_max[ptr * 2] += tmp;
		lazy_max[ptr * 2 + 1] += tmp;
	}
}

void sl_min(int ptr, int l, int r)
{
	int tmp = lazy_min[ptr];
	lazy_min[ptr] = 0;
	st_min[ptr] += tmp;
	if (l != r)
	{
		lazy_min[ptr * 2] += tmp;
		lazy_min[ptr * 2 + 1] += tmp;
	}
}

void ud_sum(int ptr, int val, int l, int r, int i)
{
	if (l > i || r < i) return;
	if (i <= l && r <= i)
	{
		st_sum[ptr] += val;
		return;
	}

	ud_sum(ptr * 2, val, l, (l + r) / 2, i);
	ud_sum(ptr * 2 + 1, val, (l + r) / 2 + 1, r, i);

	st_sum[ptr] = st_sum[ptr * 2] + st_sum[ptr * 2 + 1];
}

void ud_max(int ptr, int val, int l, int r, int i, int j)
{
	if (lazy_max[ptr]) sl_max(ptr, l, r);

	if (l > j || r < i) return;
	if (i <= l && r <= j)
	{
		st_max[ptr] += val;
		if (l != r)
		{
			lazy_max[ptr * 2] += val;
			lazy_max[ptr * 2 + 1] += val;
		}
		return;
	}

	ud_max(ptr * 2, val, l, (l + r) / 2, i, j);
	ud_max(ptr * 2 + 1, val, (l + r) / 2 + 1, r, i, j);

	st_max[ptr] = max(st_max[ptr * 2], st_max[ptr * 2 + 1]);
}

void ud_min(int ptr, int val, int l, int r, int i, int j)
{
	if (lazy_min[ptr]) sl_min(ptr, l, r);

	if (l > j || r < i) return;
	if (i <= l && r <= j)
	{
		st_min[ptr] += val;
		if (l != r)
		{
			lazy_min[ptr * 2] += val;
			lazy_min[ptr * 2 + 1] += val;
		}
		return;
	}

	ud_min(ptr * 2, val, l, (l + r) / 2, i, j);
	ud_min(ptr * 2 + 1, val, (l + r) / 2 + 1, r, i, j);

	st_min[ptr] = min(st_min[ptr * 2], st_min[ptr * 2 + 1]);
}

string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> s;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		switch (s[i])
		{
		case '(':
			if (a[cur] == ')')
			{
				ud_sum(1, 2, 0, N, cur);
				ud_max(1, 2, 0, N, cur, N);
				ud_min(1, 2, 0, N, cur, N);
			}
			else if (a[cur] != '(')
			{
				ud_sum(1, 1, 0, N, cur);
				ud_max(1, 1, 0, N, cur, N);
				ud_min(1, 1, 0, N, cur, N);
			}
			a[cur] = s[i];
			break;
		case ')':
			if (a[cur] == '(')
			{
				ud_sum(1, -2, 0, N, cur);
				ud_max(1, -2, 0, N, cur, N);
				ud_min(1, -2, 0, N, cur, N);
			}
			else if (a[cur] != ')')
			{
				ud_sum(1, -1, 0, N, cur);
				ud_max(1, -1, 0, N, cur, N);
				ud_min(1, -1, 0, N, cur, N);
			}
			a[cur] = s[i];
			break;
		case 'L':
			if (cur > 0) cur--;
			break;
		case 'R':
			cur++;
			break;
		default:
			if (a[cur] == '(')
			{
				ud_sum(1, -1, 0, N, cur);
				ud_max(1, -1, 0, N, cur, N);
				ud_min(1, -1, 0, N, cur, N);
			}
			else if (a[cur] == ')')
			{
				ud_sum(1, 1, 0, N, cur);
				ud_max(1, 1, 0, N, cur, N);
				ud_min(1, 1, 0, N, cur, N);
			}
			a[cur] = s[i];
			break;
		}
		int total = st_sum[1];
		int curMax = st_max[1];
		int curMin = st_min[1];

		if (total != 0 || curMin < 0) cout << "-1 ";
		else cout << curMax << ' ';
	}
}