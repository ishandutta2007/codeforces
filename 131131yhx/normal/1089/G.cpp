#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[111];

int solve() {
    int k;
    scanf("%d", &k);
    for(int i = 0; i < 7; i++) scanf("%d", &A[i]);
    int tot = 0;
    for(int i = 0; i < 7; i++) tot += A[i];
    int tmp = max(0, (k - 21) / tot);
    int ans = tmp * 7;
    k -= tmp * tot;
    int mn = 23333;
    for(int i = 0; i < 7; i++) {
        int s = k, nw = 1;
        for(int j = i; ; j = (j + 1) % 7, nw++)
            if(A[j] && --s == 0) break;
        mn = min(mn, nw);
    }
    return mn + ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        printf("%d\n", solve());
    }
    return 0;
}