#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int m = 0, c = 0;
    while (N--) {
        int a, b;
        scanf("%d%d", &a, &b);
        m += a > b;
        c += a < b;
    }
    if (m > c) puts("Mishka");
    else if (m < c) puts("Chris");
    else puts("Friendship is magic!^^");
    return 0;
}