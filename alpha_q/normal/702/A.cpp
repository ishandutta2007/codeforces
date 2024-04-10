#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    int len = 0, best = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1]) ++len;
        else {
            best = max(best, len);
            len = 1;
        }
    }
    best = max(best, len);

    printf("%d\n", best);
	return 0;
}