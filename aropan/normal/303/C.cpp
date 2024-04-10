#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 5001;
const int MAXX = 1000002;


int a[MAXN];
vector <int> f[MAXX];
int n, k;
int upd[MAXN], cnt;

int main()
{
	#ifdef MJUDGE
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout));
	#endif
	
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int d = a[j] - a[i];
			if ((int)f[d].size() <= k)
				f[d].push_back(j);
		}

	for (int i = 1; i < MAXX; i++)
	{
		int flg = 0;
		cnt += 1;
		for (int j = i; j < MAXX && flg <= k; j += i)
			for (int l = 0; l < (int)f[j].size(); l++)
			{
				flg += upd[f[j][l]] != cnt;
				upd[f[j][l]] = cnt;
			}
			
		if (flg <= k)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}