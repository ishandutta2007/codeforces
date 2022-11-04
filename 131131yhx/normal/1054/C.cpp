#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, L[1010], R[1010], Ans[1010];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &L[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &R[i]);
    for(int i = 1; i <= n; i++) Ans[i] = n - L[i] - R[i];
    for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j >= 1; j--) if(Ans[j] > Ans[i]) L[i]--;
        for(int j = i + 1; j <= n; j++) if(Ans[j] > Ans[i]) R[i]--;
        if(L[i] || R[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i = 1; i <= n; i++) printf("%d ", Ans[i]);
    return 0;
}