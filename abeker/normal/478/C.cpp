#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    long long a[3];
    for (int i = 0; i < 3; i++)
        scanf("%I64d", a + i);
    sort(a, a + 3);
    printf("%I64d\n", a[2] > 2 * (a[0] + a[1]) ? a[0] + a[1] : (a[0] + a[1] + a[2]) / 3);
    return 0;
}