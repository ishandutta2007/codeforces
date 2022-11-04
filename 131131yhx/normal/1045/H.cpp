#include <cstdio>
#include <cstring>
#include <algorithm>
#define P 1000000007
#define int long long

using namespace std;

typedef long long ll;

ll Fac[300010], Rev[300010];

ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

ll C(ll x, ll y) {
    return Fac[x] * Rev[y] % P * Rev[x - y] % P;
}

char A[100010], B[100010];

int c[2][2], nw[100010], n, ans = 0;

int calc(int x, int y) {
    if(x == 0) return !y;
    return C(x + y - 1, x - 1);
}

int solve(int i) {
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(c[i][j] < 0) return 0;
    if(c[i][!i] == c[!i][i] || c[i][!i] == c[!i][i] + 1) {
        return calc(c[i][!i], c[!i][!i]) * calc(c[!i][i] + 1, c[i][i]) % P;
    }
    return 0;
}

void DFS(int x, int lf = 1, int ri = 1, int lead0 = 1) {
    if(!lf && !ri || x == n + 1) {
        if(n - x + 1 != c[0][0] + c[0][1] + c[1][0] + c[1][1]) return;
        // notice lf | ri = 1 when lead0 = 1
        ans = (ans + solve(nw[x - 1])) % P;
        return;
    }
    for(int i = 0; i < 2; i++) {
        if(lf && i < A[x]) continue;
        if(ri && i > B[x]) continue;
        nw[x] = i;
        if(!lead0) c[nw[x - 1]][nw[x]]--;
        DFS(x + 1, lf && (i == A[x]), ri && (i == B[x]), lead0 && (i == 0));
        if(!lead0) c[nw[x - 1]][nw[x]]++;
    }
}

signed main() {
    for(int i = 0; i <= 300005; i++) Fac[i] = !i ? 1 : Fac[i - 1] * i % P;
    for(int i = 300005; i >= 0; i--) Rev[i] = i == 300005 ? powmod(Fac[i]) : Rev[i + 1] * (i + 1) % P;
    scanf("%s%s%lld%lld%lld%lld", A + 1, B + 1, &c[0][0], &c[0][1], &c[1][0], &c[1][1]);
    n = strlen(B + 1);
    int o = strlen(A + 1);
    for(int i = n; i > (n - o); i--) A[i] = A[i - (n - o)];
    for(int i = 1; i <= n; i++) A[i] -= '0', B[i] -= '0';
    for(int i = n - o; i >= 1; i--) A[i] = 0;
    DFS(1);
    printf("%lld\n", ans);
    return 0;
}