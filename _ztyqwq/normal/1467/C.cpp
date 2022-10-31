#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[300001];
signed main()
{
	int n1, n2, n3;
	scanf("%lld %lld %lld", &n1, &n2, &n3);
	int n = n1 + n2 + n3;
	int s1 = 0, s2 = 0, s3 = 0, m1 = 0x7fffffff, m2 = m1, m3 = m1;
	for(int i = 1; i <= n1; i++)
		scanf("%lld", &a[i]), s1 += a[i], m1 = min(m1, a[i]);
	for(int i = n1 + 1; i <= n1 + n2; i++)
		scanf("%lld", &a[i]), s2 += a[i], m2 = min(m2, a[i]);
	for(int i = n1 + n2 + 1; i <= n; i++)
		scanf("%lld", &a[i]), s3 += a[i], m3 = min(m3, a[i]);
	printf("%lld\n", s1 + s2 + s3 - 2 * min(min(min(min(min(s1, s2), s3), m1 + m2), m1 + m3), m2 + m3));
	return 0;
}