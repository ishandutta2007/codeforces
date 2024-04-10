#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000005;
const LL inf=(LL)1e18;

int n, a[N];
LL r1, r2, r3, d, w2[N], w1[N], f[N][4];

LL get1(int x)
{
	return r1 * x + r3;
}

LL get2(int x)
{
	return min(r2 + r1, r1 * (x + 2));
}

int main()
{
	scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), w1[i] = get1(a[i]), w2[i] = get2(a[i]);
	f[1][0] = 0;
	f[1][1] = inf;
	f[1][2] = inf;
	for (int i = 2; i <= n; i++)
	{
		f[i][0] = min(f[i - 1][0] + w1[i - 1], f[i - 1][2] + w2[i - 1]) + d;
		f[i][1] = min(f[i - 1][0] + w2[i - 1], f[i - 1][1] + w2[i - 1]) + d * 2;
		f[i][2] = min(f[i - 1][0] + w2[i - 1], f[i - 1][2] + w2[i - 1]) + d * 3;
	}	
	printf("%lld\n",min(f[n][0]+w1[n],min(f[n][1]+w1[n],f[n][2]+w2[n])));
	return 0;
}