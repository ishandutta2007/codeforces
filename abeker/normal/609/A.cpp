#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 105;

int N, M;
int a[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int solve() {
    sort(a, a + N, greater <int>());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
        if (sum >= M) return i + 1;
    }
    return -1;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}