#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000005;

int n;
LL b[N], a[N];

int main()
{
	scanf("%d", &n);
	LL s = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), s += a[i];
	s -= (LL)(n - 1) * (n - 2) / 2;
	LL p = s % n, fir = (s - p) / n;
	b[1] = fir;
	for (int i = 2; i <= p + 1; i++) b[i] = b[i - 1] + 1;
	b[p + 2] = b[p + 1];
	for (int i = p + 3; i <= n; i++) b[i] = b[i - 1] + 1;
	for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
	return 0;
}