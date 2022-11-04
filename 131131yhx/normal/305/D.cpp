#include <bits/stdc++.h>
#define P 1000000007

using namespace std;

int n, m, k, B[1000010], Mn = 1 << 30, Mx = 0, tot = 0, x, y, ans = 0;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i <= 1000000; i++) B[i] = !i ? 1 : (B[i - 1] + B[i - 1]) % P;
	while(m--) {
		scanf("%d%d", &x, &y);
		if(y == x + 1) continue;
		if(y != x + k + 1) return puts("0"), 0;
		tot++, Mn = min(Mn, x), Mx = max(Mx, x);
	}
	if(Mx - Mn > k) return puts("0"), 0;
	n = n - k - 1;
	for(int i = Mx == 0 ? 1 : max(Mx - k, 1); i <= min(Mn, n); i++)
		ans = (ans + B[min(n - i, k) + (i == Mn) - tot]) % P;
	return printf("%d\n", ans + (tot == 0)), 0;
}