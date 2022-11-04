#include <bits/stdc++.h>
using namespace std;
int a[305][305];
int n;
int main() {
	scanf("%d", &n);
	int i = 1, j = 1;
	for (int k = 1; k <= n * n; k++) {
		a[i][j] = k;
		if (j % 2 == 1 && i == n) j++;
		else if (j % 2 == 0 && i == 1) j++;
		else if (j % 2 == 1) i++;
		else i--;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			printf("%d%c", a[i][j], " \n"[j == n]);
	return 0;
}