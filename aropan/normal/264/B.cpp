#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXX = 1000005;

int f[MAXX];
int n;
int ans = 0;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		vector <int> a;
		
		for (int j = 2; j * j <= m; j++)
			if (m % j == 0)
			{
				a.push_back(j);
				do m /= j; while (m % j == 0);
			}
		if (m > 1)
			a.push_back(m);
			
		int res = 0;
		for (int j = 0; j < (int)a.size(); j++)
			res = max(res, f[a[j]]);

		for (int j = 0; j < (int)a.size(); j++)
			f[a[j]] = res + 1;
			
		ans = max(ans, res + 1);
	}
	printf("%d\n", ans);
	
	return 0;
}