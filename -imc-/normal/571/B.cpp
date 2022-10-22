#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxN = 5050;
ll d[maxN][maxN];

void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	sort(a.begin(), a.end());
	
	int r = n % k;
	
	const ll INF = (ll)1e18;
	
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	
	for (int totalBlocks = 0; totalBlocks < k; totalBlocks++)
		for (int plusOneBlocks = 0; plusOneBlocks <= min(r, totalBlocks); plusOneBlocks++)
		{
			ll& current = d[totalBlocks][plusOneBlocks];
			
			if (current == -1) continue;
			
			int pos = totalBlocks * (n / k) + plusOneBlocks;
			d[totalBlocks + 1][plusOneBlocks] = max(d[totalBlocks + 1][plusOneBlocks], current + (totalBlocks > 0 ? a[pos] - a[pos - 1] : 0));
			d[totalBlocks + 1][plusOneBlocks + 1] = max(d[totalBlocks + 1][plusOneBlocks + 1], current + (totalBlocks > 0 ? a[pos] - a[pos - 1] : 0));
		}
		
	ll maxSkip = d[k][r];
	ll total = a[n - 1] - a[0];
	
	//printf("n=%d, k=%d\n", n, k);
	//printf("total %lld max skip %lld\n", total, maxSkip);
	printf("%lld\n", total - maxSkip);
}

int main()
{
#ifdef LOCAL
	for (int i = 0; i < 3; i++)
#endif
	solve();
	
	return 0;
}