#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 200010

using namespace std;

int n, m, k, B[M], S[M];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for(int i = 1; i < n; i++) S[i] = B[i + 1] - B[i] - 1;
    sort(S + 1, S + n);
    int ans = n;
    int o = (n - 1) - (k - 1);
    for(int i = 1; i <= o; i++) ans += S[i];
    printf("%d\n", ans);
    return 0;
}