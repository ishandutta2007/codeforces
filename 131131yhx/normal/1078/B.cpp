#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, A[10010], S[111][11111];

int main() {
    scanf("%d", &n);
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        A[x]++;
        tot += x;
    }
    int ans = 1;
    S[0][0] = 1;
    for(int i = 1; i <= 100; i++) if(A[i])
        for(int j = 100; j >= 0; j--)
            for(int k = 10000; k >= 0; k--) {
                int sm = S[j][k];
                if(sm >= 2) continue;
                for(int s = 1; s <= A[i] && s <= j; s++)
                    if(k - s * i >= 0) {
                        if((sm += S[j - s][k - s * i]) >= 2) {
                            break;
                        }
                    }
                S[j][k] = min(sm, 2);
            }
    int ss = 0;
    for(int i = 1; i <= n; i++) ss += !!A[i];
    if(ss == 2) return printf("%d\n", n), 0;
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= A[i]; j++) {
            if(S[j][j * i] == 1) ans = max(ans, j);
            //if(S[n - j][tot - j * i] == 1) ans = max(ans, j);
        }
    printf("%d\n", ans);
    return 0;
}