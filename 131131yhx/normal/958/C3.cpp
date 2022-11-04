#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, p, X[500010], S[500010], Lf[111][111], Mn[111], Mnv[111];

ll tot = 0, ss = 0;

void add(int a, int b, int v) {
    for(int i = b; i <= p; i += i & -i) Lf[a][i] = min(Lf[a][i], v);
    if(Mn[a] > v) {
        Mn[a] = v;
    }//for(int i = b; i; i -= i & -i) Ri[a][i] = max(Ri[a][i], v);
}

int getv(int a, int b) {
    int mn = 1e9;
    for(int i = b; i; i -= i & -i) mn = min(mn, Lf[a][i]);
    if(mn == Mn[a]) return mn;
    return Mn[a] + 1;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &X[i]);
        tot += X[i];
        ss += X[i] / p;
        X[i] %= p;
        S[i] = (S[i - 1] + X[i]) % p;
    }
    for(int i = 1; i <= n; i++) S[i]++;
    memset(Lf, 63, sizeof Lf);
    memset(Mn, 63, sizeof Mn);
    add(0, 1, 0);
    int a = 0, b = 1;
    for(int i = 1; i < n; i++, swap(a, b))
        for(int j = m; j >= 1; j--)
            add(j, S[i], getv(j - 1, S[i]));
    printf("%d\n", S[n] - 1 + getv(m - 1, S[n]) * p);
    return 0;
}