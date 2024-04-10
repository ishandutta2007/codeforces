#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 100007;
const long long INF = (long long)1e+16;

int n;
vector <int> e[MAXN];
long long v[MAXN];
long long ans;
long long l[MAXN], r[MAXN];

void dfs(int x, int p = 0)
{
	long long low, high;
	low = high = 0;
	for (int i = 0; i < (int)e[x].size(); i++)
	{
		int y = e[x][i];
		if (y != p)
		{
			dfs(y, x);
			if (l[y] < low) low = l[y];
			if (high < r[y]) high = r[y];
		}
	}
	v[x] += high + low;
	if (v[x] > 0) low -= v[x];
	if (v[x] < 0) high -= v[x];
	//cout << x << " " << low << " " << high << endl;
	
	l[x] = low;
	r[x] = high;
	return;
}

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[i] = x;
	}
	dfs(1);
	cout << r[1] - l[1] << endl;
	return 0;
}