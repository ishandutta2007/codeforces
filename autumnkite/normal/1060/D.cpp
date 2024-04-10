#include <cstdio>
#include <algorithm>
int n, L[100005], R[100005];
int main(){
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i) scanf("%d%d", L + i, R + i);
    std :: sort(L + 1, L + 1 + n), std :: sort(R + 1, R + 1 + n);
    long long ans = 0;
    for (register int i = 1; i <= n; ++i) ans += std :: max(L[i], R[i]);
    printf("%lld", ans + n);
}