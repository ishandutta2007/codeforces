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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;

int main()
{
	scanf("%d%d", &n, &m);

	int chestOdd = 0, chestEven = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t % 2 == 0) chestEven++;
		else chestOdd++;
	}

	int keyOdd = 0, keyEven = 0;
	for (int i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);
		if (t % 2 == 0) keyEven++;
		else keyOdd++;
	}

	ll result = (ll)min(chestOdd, keyEven) + (ll)min(chestEven, keyOdd);

	printf("%lld", result);
}