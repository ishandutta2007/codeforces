#include <cstdio>
using namespace std;

const int MOD = (int)1e9 + 7;

int main() {
    int N;
    scanf("%d", &N);
    int a = 1, b = 1;
    while (N--) {
        a = (long long)a * 27 % MOD;
        b = (long long)b * 7 % MOD;
    }
    printf("%d\n", a >= b ? a - b : a - b + MOD);
    return 0;
}