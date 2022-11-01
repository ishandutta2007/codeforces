#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    long long i, n, ans = 1; scanf("%I64d", &n);
    if (n % 2 == 0) {
        ans *= 2;
        while (n % 2 == 0) n /= 2;
    }
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            ans *= i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 2 && ans % n) ans *= n;
    printf("%I64d\n", ans);
    return 0;
}