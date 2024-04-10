#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int n;

map <int, int> hsh1, hsh2;

map <int, int>::iterator it;

map <pair <int, int>, int> hsh3;

map <pair <int, int>, int>::iterator it2;

int X[200010], Y[200010], tmp[200010];

int main()
{
	scanf("%d", &n);
	hsh1.clear(), hsh2.clear();
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		hsh1[x]++, hsh2[y]++, hsh3[pair <int, int> (x, y)]++;
	}
	ll ans = 0;
	for(it = hsh1.begin(); it != hsh1.end(); it++) ans = ans + (1ll * it->second * (it->second - 1) / 2);
	for(it = hsh2.begin(); it != hsh2.end(); it++) ans = ans + (1ll * it->second * (it->second - 1) / 2);
	for(it2 = hsh3.begin(); it2 != hsh3.end(); it2++) ans = ans - (1ll * it2->second * (it2->second - 1) / 2);
	printf("%lld\n", ans);
	return 0;
}