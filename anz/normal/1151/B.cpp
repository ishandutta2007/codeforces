#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int n, m;
int a[501][501];
bool cache[501][1024];

vector<int> result;
bool hasPrinted = false;

void findResult(int start, vector<int> index)
{
	if (start == n)
	{
		int res = 0;
		for (int i = 0; i < index.size(); i++)
		{
			res ^= index[i];
		}
		if (res)
		{
			result = index;
			hasPrinted = true;
			return;
		}
	}

	for (int i = 0; i < 1024; i++)
	{
		if (hasPrinted) return;
		if (cache[start][i])
		{
			index.push_back(i);
			findResult(start + 1, index);
			index.pop_back();
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			cache[i][a[i][j]] = true;
		}
	}

	vector<int> tmp;
	findResult(0, tmp);

	if (hasPrinted)
	{
		printf("TAK\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (result[i] == a[i][j])
				{
					printf("%d ", j + 1);
					break;
				}
			}
		}
	}
	else
		printf("NIE");
}