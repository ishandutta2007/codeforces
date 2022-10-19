#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, x, y, z, c, d;

int main() {
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= 6; i++) {
        c = abs(a - i);
        d = abs(b - i);
        if (c < d) x++;
        else if (c > d) z++;
        else y++;
    }
    printf("%d %d %d\n", x, y, z);
    return 0;
}