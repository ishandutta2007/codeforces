#include <stdio.h>
#include <string.h>
#define MAX 3000000
using namespace std;

int W[MAX];

int main() {
    int n, w, i, steps = 0;
    memset(W, 0, sizeof W); scanf("%d", &n);
    while (n--) {scanf("%d", &w); ++W[w];}
    for (i = 0; i <= MAX; i++) {
        if (W[i] == 0) continue;
        int tmp = W[i] / 2;
        W[i] -= (2 * tmp); W[i + 1] += tmp;
        if (W[i]) ++steps;
    }
    printf("%d\n", steps);
}