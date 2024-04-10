#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		if (m <= n / k) printf("%d\n", m);
		else printf("%d\n", n / k - (m - n / k + k - 2) / (k - 1));
	}
	return 0;
}