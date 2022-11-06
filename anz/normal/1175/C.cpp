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

int arr[200005];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		int minNum = -1;
		int ans = -1;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", arr + i);
			if (i >= k)
			{
				int tmp = arr[i] - arr[i - k];
				//if (tmp < 0) tmp = -tmp;
				tmp = (tmp + 1) / 2;
				if (minNum == -1 || minNum > tmp)
				{
					minNum = tmp;
					ans = arr[i] - tmp;
				}
			}
		}
		printf("%d\n", ans);
	}
}