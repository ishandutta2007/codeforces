#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
inline int f(int x, int k)
{
	if(k == 0)
		return x - 1;
	if(k == 1)
		return x + min(x, 10000ll) - 1;
	if(k == 2 && x >= 10000)
		return x + 100019999ll;
	if(k == 3 && x >= 10000)
		return x + 1000300029999ll;
	if(k == 4 && x >= 10000)
		return x + 10004000600039999ll;
	int X = x, mn = min(x, 10000ll);
	for(int i = 0; i <= mn; i++)
		x = f(x, k - 1) + 2;
	return x - 2;
}
inline void Work(int x, int k)
{
	int mn = min(x, 10000ll);
	printf("%lld ", mn);
	vector<int> vec;
	vec.push_back(x);
	for(int i = 1; i <= mn; i++)
	{
		x = f(x, k - 1) + 1;
		printf("%lld ", x++);
		vec.push_back(x);
	}
	putchar('\n');
	fflush(stdout);
	int res;
	scanf("%lld", &res);
	assert(res != -2);
	if(res == -1)
		exit(0);
	Work(vec[res], k - 1);
}
signed main()
{
	Work(1, 5);
	return 0;
}