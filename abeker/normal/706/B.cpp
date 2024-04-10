#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N, Q;
int a[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    sort(a, a + N);
    scanf("%d", &Q);
    while (Q--) {
        int m;
        scanf("%d", &m);
        printf("%d\n", upper_bound(a, a + N, m) - a);
    }
    return 0;
}