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

int n;
int board[101][101];

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

void DFS(int x, int y, int c)
{
	board[x][y] = c;
	for (int i = 0; i < 8; i++)
	{
		int cx = x + dx[i], cy = y + dy[i];
		if (cx < 0 || cx >= n || cy < 0 || cy >= n) continue;
		if (board[cx][cy]) continue;
		DFS(cx, cy, 3 - c);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		if (board[i][j] == 0) DFS(i, j, 1);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1) cout << "B";
			else cout << "W";
		}
		cout << "\n";
	}
}