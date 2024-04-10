#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

vector < pair <int, int> > a;
int n, m, k;

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d %d", &n, &m, &k);
	a.reserve(n + m);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a.push_back(make_pair(x, 1));
	}
	
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		a.push_back(make_pair(x, -1));
	}
	
	sort(a.rbegin(), a.rend());
	
	int k = 0;
	for (int i = 0, j = 0; i < (int)a.size(); i = j)
	{
		while (j < (int)a.size() && a[i].first == a[j].first) k += a[j++].second;
		if (k > 0)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}