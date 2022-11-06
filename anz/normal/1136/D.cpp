#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int n, m;
int cq[300001];
int wh[300001];
bool isConnected[300001];
bool canGo[300001];
int back[300001];

vector<pair<int, int> >p;

bool bin_search(int a, int b)
{
	int left = 0, right = p.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		pair<int, int>tmp = p[mid];
		if (tmp.first < a)
		{
			left = mid + 1;
		}
		else if (tmp.first > a)
		{
			right = mid - 1;
		}
		else
		{
			if (tmp.second < b)
				left = mid + 1;
			else if (tmp.second>b)
				right = mid - 1;
			else return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &cq[i]);
		wh[cq[i]] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		p.push_back(make_pair(a, b));
		if (wh[a] < wh[b])
			back[a]++;
		if (b == cq[n - 1])
			isConnected[a] = true;
	}

	sort(p.begin(), p.end());

	int result = 0;
	int cnt = 0;
	vector <int> tmp;
	for (int i = n - 2; i >= 0; i--)
	{
		int curNum = cq[i];
		if (isConnected[curNum])
		{
			if (back[curNum] >= n - 1 - i - cnt)
			{
				bool flag = true;
				for (int j = 0; j < tmp.size(); j++)
				{
					if (!bin_search(curNum, tmp[j]))
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					canGo[curNum] = true;
					cnt++;
				}
				else
					tmp.push_back(curNum);
			}
			else
				tmp.push_back(curNum);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (canGo[i]) result++;
	}
	printf("%d", result);
}