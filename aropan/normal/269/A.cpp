#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x, k;
		scanf("%d %d", &k, &x);
		k++;
		for (long long j = 4; j < x; j *= 4)
			k++;
		ans = max(ans, k);
	}
	cout << ans << endl;
	return 0;
}