#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100100;

typedef pair<int, int> pii;
#define mp make_pair

int n, m, k;
bool rev;
vector<int> a[N];
const int BOUND = 11;

void clear()
{
	for (int i = 0; i < n; i++)
	{
		a[i].clear();
		a[i].resize(m);
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
	}
}

int calcSquare(int x, int y)
{
	if (x < 0 || y < 0 || x + 1 >= n || y + 1 >= m) return 0;
	return a[x][y] + a[x + 1][y] + a[x][y + 1] + a[x + 1][y + 1];
}

int evalScore(int x)
{
	if (x == 4) return 3;
	if (x == 3) return 1;
	return 0;
}

void printAns()
{
	if (!rev)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1)
					printf("*");
				else
					printf(".");
			printf("\n");
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				if (a[j][i] == 1)
					printf("*");
				else
					printf(".");
			printf("\n");
		}
	}
	return;
}

void solveStupid()
{
	clear();
	int x = 0;
	for (int i = 0; x < k &&i < n; i++)
		for (int j = 0; x < k && j < m; j++)
		{
			int oldX = x;
			a[i][j] = 1;
			x += evalScore(calcSquare(i - 1, j - 1));
			x += evalScore(calcSquare(i - 1, j));
			if (x > k)
			{
				a[i][j] = 0;
				x = oldX;
			}
		}
	if (x != k) throw;
	printAns();
	return;
}

int off(int x, int y)
{
	if (a[x][y] == 0) throw;
	int res = 0;
	res += evalScore(calcSquare(x - 1, y - 1));
	res += evalScore(calcSquare(x - 1, y));
	res += evalScore(calcSquare(x, y - 1));
	res += evalScore(calcSquare(x, y));
	a[x][y] = 0;
	return res;
}

void solveBrute()
{
	clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 1;
	k = 4 * (n - 1) * (m - 1) - k;
//	printf("%d\n", k);
	vector<pii> pos;
	pos.push_back(mp(0, 0));
	pos.push_back(mp(1, 0));
	pos.push_back(mp(0, 1));
	pos.push_back(mp(0, 2));
	pos.push_back(mp(0, m - 1));
	pos.push_back(mp(n - 1, 0));
	pos.push_back(mp(n - 1, m - 1));
//	pos.push_back(mp(1, 1));
	if (m > 3)
		pos.push_back(mp(0, 3));

	sort(pos.begin(), pos.end());
	pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
	int w = (int)pos.size();
	for (int mask = 0; mask < (1 << w); mask++)
	{
		if (mask > 0 && ((mask & 1) == 0)) continue;
		for (int i = 0; i < w; i++)
			a[pos[i].first][pos[i].second] = 1;
		int cur = k;
		for (int i = 0; i < w; i++)
		{
			if (((mask >> i) & 1) == 0) continue;
			cur -= off(pos[i].first, pos[i].second);
		}
		if (cur == 0)
		{
			printAns();
			return;
		}
	}
	printf("-1\n");
	return;
}

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	if(k == 0){
	     for(int i = 0; i < n; i++){
	          for(int j = 0; j < m; j++){
	               if(i == 0 && j ==0) printf("*");
	               else printf(".");
	          }
	          printf("\n");
	     }
	     return;
	}
	rev = 0;
	if (n > m)
	{
		swap(n, m);
		rev = 1;
	}
	int delta = 4 * (n - 1) * (m - 1) - k;
	if (delta < 0)
	{
		printf("-1\n");
		return;
	}
	if (delta >= BOUND)
	{
		solveStupid();
		return;
	}
	solveBrute();
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--)
	{
		solve();
		if (t != 0) printf("\n");
//		printf("\n");
	}

	return 0;
}