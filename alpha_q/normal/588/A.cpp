#include <stdio.h>

using namespace std;

int main() {
    int i, n, a, p, res, crnt;
    scanf("%d %d %d", &n, &a, &crnt); res = a * crnt;
    for (i = 2; i <= n; i++) {
        scanf("%d %d", &a, &p);
        if (p < crnt) crnt = p;
        res += a * crnt;
    }
    printf("%d\n", res);
    return 0;
}