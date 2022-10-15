#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 100007;

int n, d;
int a[MAXN];
long long ans;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j < n && a[j] - a[i] <= d) j++;
		long long k = j - i - 1;
		ans += k * (k - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}