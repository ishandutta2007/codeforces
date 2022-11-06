#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int Case, n, k;
set<int> S;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		S.clear();
		scanf("%d%d", &n, &k);
		bool ok = false;
		for (int i = 1, x; i <= n; i ++)
		{
			scanf("%d", &x);
			if (S.count(x + k) != 0 || S.count(x - k) != 0)
				ok = true;
			S.insert(x);
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}