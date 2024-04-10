#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k1, k2, w, b;
		scanf("%d %d %d", &n, &k1, &k2);
		scanf("%d %d", &w, &b);
		int ww = min(k1, k2) + abs(k1 - k2) / 2, bb = min(n - k1, n - k2) + abs(k1 - k2) / 2;
		if(w > ww || b > bb)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}