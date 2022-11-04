#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, A[100010];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for(int i = n; i >= 2; i--) A[i] = (A[i] != A[i - 1]);
    int nw = 0, ans = 0;
    for(int i = 2; i <= n; i++) {
        if(A[i] == 1) nw++; else nw = 0;
        ans = max(ans, nw);
    }
    printf("%d\n", ans + 1);
    return 0;
}