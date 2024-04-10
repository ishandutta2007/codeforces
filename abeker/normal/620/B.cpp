#include <cstdio>
using namespace std;

const int segments[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calc(int x) {
    int res = 0;
    for (; x; x /= 10)
        res += segments[x % 10];
    return res;
}

int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    int tot = 0;
    for (int i = A; i <= B; i++)
        tot += calc(i);
    printf("%d\n", tot);
    return 0;
}