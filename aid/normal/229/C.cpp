#include <cstdio>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int d[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int v, u;
        scanf("%d %d", &v, &u);
        v--;
        u--;
        d[v]++;
        d[u]++;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += (long long)d[i] * (2 * d[i] - n) +
            (long long)(n - d[i] - 1) * (n - d[i] - 2);
    ans /= 6;
    printf("%I64d\n", ans);
    return 0;
}