#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

int Ans[1010];

int Do(int a, int b, int c) {
    printf("? %lld %lld %lld\n", a, b, c);
    fflush(stdout);
    int x;
    scanf("%lld", &x);
    return x;
}

int getsm(int a, int b, int c, int d) {
    int Ans[4];
    Ans[0] = Do(a, b, c);
    Ans[1] = Do(a, b, d);
    Ans[2] = Do(a, c, d);
    Ans[3] = Do(b, c, d);
    sort(Ans, Ans + 4);
    return Ans[0] + Ans[3];
}

signed main() {
    int n;
    scanf("%lld", &n);
    int S[5];
    S[0] = getsm(1, 2, 3, 4);
    S[1] = getsm(1, 2, 3, 5);
    S[2] = getsm(1, 2, 4, 5);
    S[3] = getsm(1, 3, 4, 5);
    S[4] = getsm(2, 3, 4, 5);
    int tot = S[0] + S[1] + S[2] + S[3] + S[4];
    for(int i = 0; i < 5; i++)
        Ans[5 - i] = tot / 4 - S[i];
    for(int i = 6; i <= n; i++) {
        int s = getsm(1, 2, 3, i);
        Ans[i] = s - Ans[1] - Ans[2] - Ans[3];
    }
    putchar('!');
    for(int i = 1; i <= n; i++) printf(" %lld", Ans[i]);
    putchar('\n');
    fflush(stdout);
    return 0;
}