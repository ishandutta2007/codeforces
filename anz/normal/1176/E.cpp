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
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n, m;
vector <int> graph[200001];
vector <pii> cnt;
int real_cnt[200001];
int cache[200001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) cache[i] = 0, real_cnt[i] = 0;
		cnt.clear();
		cnt.resize(n + 1);
		for (int i = 1; i <= n; i++) cnt[i] = { 0,i };
		for (int i = 1; i <= n; i++) graph[i].clear();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
			cnt[a].first++, cnt[b].first++;
			real_cnt[a]++, real_cnt[b]++;
		}

		sort(cnt.begin(), cnt.end());

		vector <int> ans;
		for (int i = 1; i <= n; i++)
		{
			int cV = cnt[i].second;
			if (cache[cV] == 1) continue;

			int maxIndex = -1;
			int maxNum = -1;
			for (int j = 0; j < graph[cV].size(); j++)
			{
				int tmp = graph[cV][j];
				if (maxNum < real_cnt[tmp])
				{
					maxNum = real_cnt[tmp];
					maxIndex = tmp;
				}
			}

			cV = maxIndex;

			ans.push_back(maxIndex);
			cache[cV] = 1;
			real_cnt[cV] = 0;
			for (int j = 0; j < graph[cV].size(); j++)
			{
				int tmp = graph[cV][j];
				cache[tmp] = 1;
				real_cnt[tmp]--;
			}
		}

		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	}
}