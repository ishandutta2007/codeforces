#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll a[300001];
int main()
{
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]), sum += a[i];
	sort(a, a + n);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int q;
		scanf("%d", &q);
		printf("%lld\n", sum - a[n - q]);
	}
}