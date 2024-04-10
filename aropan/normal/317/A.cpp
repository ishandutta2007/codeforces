#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

long long x, y, m;
long long ans = 0;

int main()
{
	cin >> x >> y >> m;
	if (x < y)
		swap(x, y);
	if (x >= m)
	{
		puts("0");
		return 0;
	}

	if (x <= 0)
	{
		puts("-1");
		return 0;
	}
	
	if (y < 0)
	{
		ans = -y / x;
		y += x * ans;
	}
	
	while (x < m)
	{
		y += x;
		if (x < y)
			swap(x, y);
		ans += 1;
	}
	cout << ans << endl;
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}