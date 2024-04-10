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


int main()
{
	int n;
	scanf("%d", &n);
	int arr[50];
	arr[4] = 0, arr[8] = 1, arr[15] = 2, arr[16] = 3, arr[23] = 4, arr[42] = 5;

	int ans = 0;
	int cnt[6] = { 0, };
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		int tmp = arr[a];

		bool flag = true;

		if (tmp && cnt[tmp] >= cnt[tmp - 1])
			flag = false;

		if (flag)
		{
			cnt[tmp]++;
			if (a == 42)
			{
				ans++;
				for (int j = 0; j < 6; j++) cnt[j]--;
			}
		}
	}

	printf("%d", n - 6 * ans);
}