#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, p;

int X[100010], L[100010], R[100010];

int main() {
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for(int i = 1; i <= n; i++) L[i] = (L[i - 1] + X[i]) % p;
    for(int i = n; i >= 1; i--) R[i] = (R[i + 1] + X[i]) % p;
    int ans = 0;
    for(int i = 2; i <= n; i++) ans = max(ans, L[i - 1] + R[i]);
    printf("%d\n", ans);
}