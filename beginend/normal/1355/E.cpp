#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, a[N];
LL w1, w2, w3;

LL solve(int h)
{
	LL s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > h) s1 += a[i] - h;
		else s2 += h - a[i];
	LL d = min(s1, s2);
	return min(w3 * d + w1 * (s2 - d) + w2 * (s1 - d), w1 * s2 + w2 * s1);
}

int main()
{
	scanf("%d%lld%lld%lld", &n, &w1, &w2, &w3);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 0, r = 1e9;
	while (r - l >= 3)
	{
		int mid = (l + r) / 2;
		LL p1 = solve(mid), p2 = solve(mid + 1);
		if (p1 <= p2) r = mid;
		else l = mid + 1;
	}
	LL mn = 1e18;
	for (int i = l; i <= r; i++) mn = min(mn, solve(i));
	printf("%lld\n", mn);
	return 0;
}