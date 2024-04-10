#include <cstdio>
#include <algorithm>
using namespace std;

bool prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (!(x % i)) return false;
    return true;
}

int two(int x) {
    for (int i = 1; i < x; i++)
        if (prime(i) && prime(x - i)) 
            return i;
    return -1;
}

void three(int x) {
    for (int i = max(x - 300, 1); i < x; i++) {
        if (!prime(i)) continue;
        int tmp = two(x - i);
        if (tmp == -1) continue;
        printf("3\n%d %d %d\n", i, tmp, x - i - tmp);
        break;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    if (prime(N)) {
        printf("1\n%d\n", N);
        return 0;
    }
    if (N < 1000) {
        int tmp = two(N);
        if (tmp != -1) {
            printf("2\n%d %d\n", tmp, N - tmp);
            return 0;
        }
    }
    three(N);
    return 0;
}