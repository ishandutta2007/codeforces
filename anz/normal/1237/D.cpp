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

int n;
int a[200001];

int ans[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n; i < n + n; i++) a[i] = a[i - n];

	deque <pii> q;
	for (int i = 0; i < n + n; i++)
	{
		while (!q.empty() && q.back().first < a[i]) q.pop_back();
		while (!q.empty() && q.front().first > a[i] * 2)
		{
			ans[q.front().second] = i - q.front().second;
			q.pop_front();
		}
		q.push_back({ a[i],i });
	}

	int si = -1;
	for (int i = 0; i < n; i++)
	{
		if (ans[i])
		{
			si = i;
			break;
		}
	}

	if (si == -1)
	{
		for (int i = 0; i < n; i++) cout << "-1 ";
		return 0;
	}

	int curNum = ans[si];
	for (int i = (si + n - 1) % n; i != si; i = (i + n - 1) % n)
	{
		if (ans[i] == 0) ans[i] = ++curNum;
		else curNum = ans[i];
	}

	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}