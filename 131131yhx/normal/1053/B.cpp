#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

bool B[300010];

int n, A[300010], S[300010], ans = 0;

void Do(int x) {
    for(int i = x, a = S[i]; i >= 1; i--, a -= S[i]) {
        int b = a;
        if(a > 0) for(int j = x + 1; j <= n + 1; j++) {
            if(!(b & 1)) ans--;
            b -= S[j];
            if(b <= 0) break;
        } else return;
    }
}

#undef int
int main() {
#define int long long
    scanf("%lld", &n);
    int _0 = 1, _1 = 0;
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for(int i = 1; i <= n; i++) {
        B[i] = B[i - 1] ^ ((S[i] = __builtin_popcountll(A[i])) & 1);
        if(B[i] == 0) ans += _0, _0++; else ans += _1, _1++;
    }
    for(int i = 1; i <= n; i++) Do(i);
    printf("%lld\n", ans);
    return 0;
}