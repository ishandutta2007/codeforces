#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 100007;

int n, k;
pair <int, int> a[MAXN];
int ans;
bool last;

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d %d", &n, &k);
	if (k == 1)
	{
		printf("%d\n", n);
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].second);
		int x = a[i].second;
		while (x % k == 0)
			x /= k;
		a[i].first = x;
	}
	sort(a, a + n);
	
	
	for (int i = 0, j = 0; i < n; i = j)
	{
		while (j < n && a[i].first == a[j].first)
			j++;
			
		ans++;
		last = true;
		for (int l = i + 1; l < j; l++)
		{
			last = a[l - 1].second * (long long)k != a[l].second || !last;
			if (last)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}