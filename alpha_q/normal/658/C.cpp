#include <bits/stdc++.h>

using namespace std;

int main() {	
	//freopen("input.txt", "r", stdin);

	int n, d, h;
	scanf("%d %d %d", &n, &d, &h);
	if (d > h + h or (n > 2 and d == 1)) {
		printf("-1\n");
		return 0;
	}

	for (int i = 1; i <= h; i++) printf("%d %d\n", i, i + 1);
	for (int i = 1; i <= d - h; i++)
		printf("%d %d\n", i == 1 ? 1 : i + h, i + h + 1);
	for (int i = d + 2; i <= n; i++) printf("%d %d\n", h, i);
    return 0;
}