#include <cstdio>
using namespace std;

const int MAXV = 1005;

int gl[2 * MAXV], sp[2 * MAXV];

int main() {
    int N;
    scanf("%d", &N);
    long long sol = 0;
    while (N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        sol += gl[x - y + MAXV]++;
        sol += sp[x + y]++;
    }
    printf("%I64d\n", sol);
    return 0;
}