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

int cnt[100001];

int cntOfcnt[100001];

set <int> tmp;

int main()
{
	scanf("%d", &n);
	int ans = 1;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &u[i]);
		cnt[u[i]]++;

		cntOfcnt[cnt[u[i]]]++;

		tmp.insert(cnt[u[i]]);
		if (cnt[u[i]] != 1)
		{
			cntOfcnt[cnt[u[i]] - 1]--;
			if (cntOfcnt[cnt[u[i]] - 1] == 0)
				tmp.erase(cnt[u[i]] - 1);
		}

		if (tmp.size() == 1)
		{
			int num = (*tmp.begin());
			if (num == 1) ans = i + 1;
			if (cntOfcnt[num] == 1) ans = i + 1;
		}
		else if (tmp.size() == 2)
		{
			auto idx = tmp.begin();
			int num1, num2;
			num1 = *idx;
			idx++;
			num2 = *idx;

			if (num1 == 1 && cntOfcnt[1] == 1)
				ans = i + 1;
			if (num2 == num1 + 1 && cntOfcnt[num2] == 1)
				ans = i + 1;
		}
	}

	printf("%d", ans);
}