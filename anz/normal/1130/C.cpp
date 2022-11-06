#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <unordered_map>
#include <bitset>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		for (; b; a %= b, swap(a, b));
		return a;
	}
	return a;
}

int n;
int r1, c1, r2, c2;

int landStart[60][60];
int landEnd[60][60];

int board[60][60];
int cache[60][60];

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

bool DFS(int x, int y, int rx, int ry, bool flag)
{
	cache[x][y] = 1;
	if (flag)
		landStart[x][y] = 1;
	else
		landEnd[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i], cy = y + dy[i];
		if (cx <= 0 || cy <= 0 || cx > n || cy > n) continue;
		if (board[cx][cy]) continue;
		if (cache[cx][cy]) continue;
		bool ans = DFS(cx, cy, rx, ry, flag);
		if (ans) return true;
	}

	return false;
}

int main()
{
	scanf("%d", &n);
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	for (int i = 1; i <= n; i++)
	{
		char str[60];
		scanf("%s", str);
		for (int j = 0; j < n; j++)
		{
			if (str[j] == '0') board[i][j + 1] = 0;
			else board[i][j + 1] = 1;
		}
	}

	memset(cache, 0, sizeof cache);
	if (DFS(r1, c1, r2, c2, true))
	{
		printf("0");
		return 0;
	}

	DFS(r2, c2, r1, r2, false);

	int ans = 987654321;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (landStart[i][j] == 0) continue;
		for (int x = 1; x <= n; x++) for (int y = 1; y <= n; y++)
		{
			if (landEnd[x][y] == 0) continue;
			int tmp = (i - x)*(i - x) + (j - y)*(j - y);
			ans = min(ans, tmp);
		}
	}

	printf("%d", ans);

}