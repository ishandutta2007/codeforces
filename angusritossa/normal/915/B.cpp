#include <bits/stdc++.h>
using namespace std;
int n, pos, l, r;
int main()
{
	scanf("%d%d%d%d", &n, &pos, &l, &r);
	int ans1 = abs(pos-l);
	if (l != 1) ans1++;
	if (r != n) ans1 += 1 + abs(l-r);
	int ans2 = abs(pos-r);
	if (l != 1) ans2 += 1 + abs(l-r);
	if (r != n) ans2++;
	if (l == 1 && r == n) printf("0\n");
	else printf("%d\n", min(ans1, ans2));
}