#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

int n, a[N]; 

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	int x = a[1], i = 1;
	while (i <= n and a[i] == x) ++i;
	int y = a[n], j = n;
	while (j >= 1 and a[j] == y) --j;
	printf("%d\n", max(0, j - i + 1));
    return 0;
}