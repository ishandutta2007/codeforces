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
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, q;
vector <pii>painter;
vector <vector<int> > fence;

int one[5001];
int two[5001][5001];

int main()
{
	scanf("%d%d", &n, &q);

	fence.resize(n+1);
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		painter.push_back({ l, r });
		for (int j = l; j <= r; j++)
			fence[j].push_back(i);
	}

	int notPainted = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fence[i].size() == 0) notPainted++;
		else if (fence[i].size() == 1)
		{
			one[fence[i][0]]++;
		}
		else if (fence[i].size() == 2)
		{
			two[fence[i][0]][fence[i][1]]++;
		}
	}

	int result = 0;
	for (int i = 0; i < q - 1; i++)
	{
		for (int j = i + 1; j < q; j++)
		{
			int cNum = n - notPainted - one[i] - one[j] - two[i][j];
			result = max(result, cNum);
		}
	}


	printf("%d", result);
}