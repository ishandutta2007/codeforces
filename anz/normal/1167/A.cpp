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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		char st[101];
		scanf("%s", st);

		bool flag = true;
		int eight = -1;
		for (int i = 0; i < n; i++)
		{
			if (st[i] == '8')
			{
				eight = i;
				break;
			}
		}

		if (eight == -1) flag = false;
		else if (n - eight - 1 < 10) flag = false;

		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}