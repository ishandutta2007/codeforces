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

int n, m;
int a[300001][10];

int all;
vector <int> cnt[1<<8];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	all = (1 << m) - 1;

	int lo = 0, hi = 1e9 + 1;
	while (lo+1 < hi)
	{
		for (int i = 0; i <= all; i++) cnt[i].clear();

		int mid = (lo + hi) / 2;
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] >= mid) tmp += (1 << j);
			}
			cnt[tmp].push_back(i);
		}

		bool hasAns = false;
		for (int i = 0; i <= all; i++)
		{
			for (int j = 0; j <= all; j++)
			{
				if ((i | j) != all) continue;
				if (cnt[i].size() && cnt[j].size())
				{
					hasAns = true;
				}
			}
		}

		if (hasAns) lo = mid;
		else hi = mid;
	}

	for (int i = 0; i <= all; i++) cnt[i].clear();

	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] >= lo) tmp += (1 << j);
		}
		cnt[tmp].push_back(i);
	}

	for (int i = 0; i <= all; i++)
	{
		for (int j = 0; j <= all; j++)
		{
			if ((i | j) != all) continue;
			if (cnt[i].size() && cnt[j].size())
			{
				cout << cnt[i].back()+1 << ' ' << cnt[j].back()+1;
				return 0;
			}
		}
	}
}