#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int N;
int occ[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        occ[x]++;
    }
    printf("%d\n", N - *max_element(occ, occ + MAXN));
    return 0;
}