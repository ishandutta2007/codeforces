#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long k;
int a[100100];
int res[200200];
int q;

long long cnt(int m)
{
	long long res = 0;
	for(int i = 0; i < n; i++) res += min(a[i], m);
	return res;
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	int low = 0, high = 1e9+10;
	while(low + 1 < high)
	{
		int mid = (low+high) / 2;
		if(cnt(mid) < k) low = mid;
		else high = mid;
	}
	k -= cnt(low);
	for(int i = 0; i < n; i++) a[i] = max(0, a[i] - low);
	for(int i = 0; i < n; i++) if(a[i] > 0) res[q++] = i;
	if(low > 1e9+1)
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 0; i < k; i++) if(a[res[i]] > 1) res[q++] = res[i];
	for(int i = k; i < q; i++) printf("%d ", res[i]+1);
	printf("\n");
	return 0;
}