#include <iostream>
#include <algorithm>

int main() {
    int ans = 0;
    int cur = 0;
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d%d", &a, &b);
	cur -= a;
	cur += b;
	if (cur > ans)
	    ans = cur;
    }
    printf("%d\n", ans);
}