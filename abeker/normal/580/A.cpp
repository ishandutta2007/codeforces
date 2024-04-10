#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int len = 0, sol = 0;
    int last = 0;
    while (N--) {
        int x;
        scanf("%d", &x);
        if (x < last) len = 0;
        sol = max(sol, ++len);
        last = x;
    }
    printf("%d\n", sol);
    return 0;
}