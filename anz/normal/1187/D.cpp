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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

const int INF = 987654321;
vector <int> segTree;

int left(int n) { return n << 1; }
int right(int n) { return (n << 1) + 1; }

void update(int n, int v, int l, int r, int i, int j)
{
	if (j < l || r < i) return;
	if (i <= l && r <= j)
	{
		segTree[n] = v;

		return;
	}
	update(left(n), v, l, (l + r) / 2, i, j);
	update(right(n), v, (l + r) / 2 + 1, r, i, j);

	segTree[n] = max(segTree[left(n)], segTree[right(n)]);
}

int getMax(int n, int l, int r, int i, int j)
{
	if (j < l || r < i) return -1;
	if (i <= l && r <= j)
	{
		return segTree[n];
	}
	int lSum = getMax(left(n), l, (l + r) / 2, i, j);
	int rSum = getMax(right(n), (l + r) / 2 + 1, r, i, j);
	return max(lSum, rSum);
}

int n;
pii b[300001];

vector <int> wh[300001];
int cnt[300001];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		segTree.resize(n * 4);
		for (int i = 1; i <= n; i++)
		{
			wh[i].clear();
			cnt[i] = 0;
			update(1, -1, 0, n - 1, i-1, i-1);
		}

		for (int i = 0; i < n; i++)
		{
			int t; scanf("%d", &t);
			wh[t].push_back(i);
		}

		bool ans = true;
		for (int i = 0; i < n; i++)
		{
			b[i].second = i + 1;
			scanf("%d", &b[i].first);
		}

		sort(b, b + n);

		for (int i = 0; i < n; i++)
		{
			int t = b[i].first;
			int d = b[i].second;
			if (cnt[t] >= wh[t].size())
			{
				ans = false;
				break;
			}
			int dir = wh[t][cnt[t]++];

			int res = getMax(1, 0, n - 1, 0, dir);
			if (res > d)
			{
				ans = false;
				break;
			}

			update(1, d, 0, n - 1, dir, dir);
		}

		if (ans) printf("YES\n");
		else printf("NO\n");
	}
}