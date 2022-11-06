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

int block[5][2] =
{
{0,0},
{1,-1},
{1,0},
{1,1},
{2,0}
};

int n;
char board[51][51];

bool isCompleted()
{
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		if (board[i][j] == '.') return false;

	return true;
}

bool canSolve(int x, int y)
{ // x,y  
	for (int i = 0; i < 5; i++)
	{
		int cx = x + block[i][0];
		int cy = y + block[i][1];

		if (cx < 0 || cx >= n || cy < 0 || cy >= n) return false;
		if (board[cx][cy] == '#') return false;
		board[cx][cy] = '#';
	}

	if (isCompleted()) return true;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		if (board[i][j] == '.')
			return canSolve(i, j);
	}

	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);

	bool result = false;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '.')
			{
				result = canSolve(i, j);
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (result) printf("YES");
	else printf("NO");
}