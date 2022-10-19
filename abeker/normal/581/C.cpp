#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N, K;
int a[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

bool cmp(const int &l, const int &r) {
    return l % 10 > r % 10;
}

int solve() {
    sort(a, a + N, cmp);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int tmp = min((10 - a[i] % 10) % 10, K);
        a[i] += tmp;
        K -= tmp;
        sum += a[i];
    }
    if (K) return min(10 * N, (sum + K) / 10);
    int sol = 0;
    for (int i = 0; i < N; i++) 
        sol += a[i] / 10;
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}