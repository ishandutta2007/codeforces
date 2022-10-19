#include <cstdio>
using namespace std;

int main() {
    int a, b, c = 0;
    scanf("%d%d", &a, &b);
    a *= b;
    while (a >= b) {
        int d = 0;
        while (a) {
            c += a / b;
            d += a % b;
            a /= b;
        }
        a = d;
    }
    printf("%d\n", c);
    return 0;
}