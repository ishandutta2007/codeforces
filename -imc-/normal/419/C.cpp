#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

pair<int, int> order(int i, int j)
{
	if (i > j) swap(i, j);
	return make_pair(i, j);
}

typedef long long ll;

void solve()
{
	int n, need;
	scanf("%d %d", &n, &need);
	
	vector<int> d(n);
	
	map<pair<int, int>, int> lower;
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		
		lower[order(x, y)]++;
		d[x]++;
		d[y]++;
	}
	
	#ifdef LOCAL
	for (int i = 0; i < n; i++)
		printf("d[%d] is %d\n", i + 1, d[i]);
	#endif
	
	ll answer = 0;
	
	vector<int> dSorted = d;
	sort(dSorted.begin(), dSorted.end());
	
	for (int i = 0; i < n; i++)
	{
		int iNotLess = lower_bound(dSorted.begin(), dSorted.end(), need - d[i]) - dSorted.begin();
		int nNotLess = n - 1 - iNotLess + 1;
		
		if (2 * d[i] >= need) nNotLess--;
		
		answer += nNotLess;
	}
	
	assert(answer % 2 == 0);
	answer /= 2;
	
	#ifdef LOCAL
	printf("pure answer\n");
	cout << answer << endl;
	#endif
	
	for (auto it: lower)
	{
		auto key = it.first;
		auto value = it.second;
		
		int real = d[key.first] + d[key.second] - value;
		if (real < need && d[key.first] + d[key.second] >= need)
		{
			#ifdef LOCAL
			printf("purged\n");
			#endif
			answer--;
		}
	}
	
	cout << answer << endl;
}

int main()
{
	#ifdef LOCAL
	freopen("c.in", "r", stdin);
	int nTests;
	scanf("%d", &nTests);
	for (int i = 0; i < nTests; i++)
	{
		solve();
		printf("\n");
	}
	#else
	solve();
	#endif
	
	return 0;
}