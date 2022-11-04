#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll F[444][444], Ans[444], Fac[444], O[444], n, P;

int MxN = 400;

void add(ll &x, ll y) {x = (x + y) % P;}

int main() {
    scanf("%lld%lld", &n, &P);
    for(int i = 0; i <= MxN; i++) Fac[i] = !i ? 1 : Fac[i - 1] * i % P;
    Ans[1] = 1;
    Ans[2] = 2;
    F[0][0] = 1;
    F[1][1] = 1;
    F[2][1] = 2;
    F[2][2] = 1;
    O[1] = 1;
    O[2] = 1;
    for(int i = 3; i <= MxN; i++) {
        O[i] = Fac[i];
        for(int j = 1; j < i; j++)
            add(O[i], -O[j] * Fac[i - j]);
    }
    for(int i = 3; i <= MxN; i++) {
        for(int j = 1; j <= i; j++)
            for(int k = 1; k <= i; k++)
                add(F[i][j], F[i - k][j - 1] * Fac[k]);
        ll tot = Fac[i];
        for(int j = 3; j < i; j++)
            add(tot, -F[i][j] * Ans[j]);
        for(int j = 1; j < i; j++)
            add(tot, -2ll * Fac[j] % P * O[i - j]);
        Ans[i] = tot;
    }
    while(n--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", (Ans[x] % P + P) % P);
    }
    return 0;
}