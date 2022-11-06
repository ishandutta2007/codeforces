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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int maxNum = -1;
int queryCnt = 0;

bool makeQuestion(vector<int> v)
{
	vector <int> sizes;
	sizes.push_back(v.size() / 2);
	int swapSize = v.size() / 2;
	do
	{
		//if (queryCnt >= 9) return true;
		printf("%d %d ", v.size() / 2, v.size() / 2);
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		fflush(stdout);
		queryCnt++;

		int num;
		scanf("%d", &num);
		if (num == -1)
		{
			return false;
		}
		maxNum = max(maxNum, num);

		int haveToBreak = true;
		vector <int> new_sizes;
		for (int i = 0; i < sizes.size(); i++)
		{
			int curSize = sizes[i];
			if (curSize > 1)
			{
				haveToBreak = false;
				new_sizes.push_back(curSize / 2);
				new_sizes.push_back(curSize - curSize / 2);
			}
			else
				new_sizes.push_back(curSize);
		}

		sizes = new_sizes;

		if (haveToBreak) break;

		int cnt = 0;
		bool flag = true;

		for (int i = 0; i < sizes.size(); i++)
		{
			for (int j = 0; j < sizes[i]; j++)
			{
				if (flag) swap(v[cnt], v[v.size() / 2 + cnt]);
				cnt++;
			}
			flag = !flag;
		}


	} while (true);

	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		maxNum = -1;
		queryCnt = 0;
		int n;
		scanf("%d", &n);

		vector <int> v;

		int tNum = n;
		if (n % 2 == 1) tNum--;
		for (int i = 0; i < tNum; i++)
			v.push_back(i + 1);

		if (!makeQuestion(v))
			return 0;

		if (n % 2 == 1)
		{
			printf("%d %d ", n - 1, 1);
			for (int i = 1; i <= n; i++)
				printf("%d ", i);
			printf("\n");
			fflush(stdout);

			int res;
			scanf("%d", &res);
			maxNum = max(maxNum, res);
		}
		printf("-1 %d\n", maxNum);
		fflush(stdout);
	}
}