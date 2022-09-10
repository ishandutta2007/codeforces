#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int v = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        v += x;
    }

    printf("%d\n", v);
	return 0;
}