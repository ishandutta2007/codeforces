#include <stdio.h>
#include <string.h>

int i, u, v, t, m, n, a[200007][2], d[200007], c;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(a, 0, sizeof(a[0]) * (n + 1));
		memset(d, 0, sizeof(d[0]) * (n + 1));

		while (m--) {
			scanf("%d %d", &u, &v);
			a[u][!!a[u][0]] = v;
		}

		c = 0;
		for (u = 1; u <= n; ++u) {
			if (d[u] == 2) {
				++c;
				continue;
			}

			for (i = 0; i < 2; ++i) if ((v = a[u][i])) {
				if (d[v] < d[u] + 1) d[v] = d[u] + 1;
			}
		}

		printf("%d ", c);
		for (i = 1; i <= n; ++i)
			if (d[i] == 2) printf("%d ", i);
		putchar('\n');
	}
}