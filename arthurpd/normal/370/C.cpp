#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[112345];
int tab[1123];

int main(void)
{
	int n, m, mx = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; mx = max(mx, ++tab[a[i]]), i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	printf("%d\n", (2*mx > n) ? (n - (2*mx - n)) : n);
	for(int i = 0; i < n; i++)
		printf("%d %d\n", a[i], a[(i + mx) % n]);
}