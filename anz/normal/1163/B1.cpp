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
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n;
int u[100001];

int cnt[11];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &u[i]);

	int ans = 1;

	int max_num = 0;
	for (int i = 0; i < n; i++)
	{
		cnt[u[i]]++;
		max_num = max(max_num, cnt[u[i]]);
		
		set <int> tmp;
		for (int i = 1; i <= 10; i++)
		{
			if (cnt[i]) tmp.insert(cnt[i]);
		}
		if (tmp.size() <= 2)
		{
			if (tmp.size() == 2)
			{
				auto ii = tmp.begin();
				auto jj = ii;
				jj++;

				if ((*ii) == 1 || (*jj) == 1)
				{
					int isOne = 0;
					for (int j = 1; j <= 10; j++)
					{
						if (cnt[j] == 1) isOne++;
					}
					if (isOne == 1)
						ans = i + 1;
				}

				if ((*ii) == (*jj) + 1)
				{
					int tmp = 0;
					for (int j = 1; j <= 10; j++)
					{
						if (cnt[j] == (*ii)) tmp++;
					}
					if (tmp == 1)
						ans = i + 1;
				}
				else if ((*jj) == (*ii) + 1)
				{
					int tmp = 0;
					for (int j = 1; j <= 10; j++)
					{
						if (cnt[j] == (*jj)) tmp++;
					}
					if (tmp == 1)
						ans = i + 1;
				}
			}
			else
			{
				if ((*tmp.begin()) == 1)
					ans = i + 1;

				int notZero = 0;
				for (int j = 1; j <= 10; j++)
					if (cnt[j]) notZero++;

				if (notZero == 1)
					ans = i + 1;
			}
		}
	}

	printf("%d", ans);
}