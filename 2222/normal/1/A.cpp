#define __USE_MINGW_ANSI_STDIO    1

#include <cstdio>

int main(){
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    freopen("x.out", "w", stdout);
    #endif
    int n, m, a;
    scanf("%d%d%d", &n, &m, &a);
    printf("%lld\n", (long long)((n - 1) / a + 1) * ((m - 1) / a + 1));
    return 0;
}