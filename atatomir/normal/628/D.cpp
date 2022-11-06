#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 2016
#define mod 1000000007

ll m, d, n;
ll any[maxN][maxN], any2[maxN][maxN];
char a[maxN], b[maxN];
ll ans;

ll poww[maxN];

void pre() {
    int i, j, k, bg, en;

    any[0][0] = 1;

    for (i = 0; i <= 9; i++)
        if (i != d)
            any[1][i % m]++;
    for (i = 2; i <= n; i++) {
        bg = (i % 2 == 0 ? d : 0);
        en = (i % 2 == 0 ? d : 9);
        bool jmp = (i % 2 == 1);

        for (j = 0; j < m; j++) {
            if (any[i - 1][j] == 0) continue;

            for (k = bg; k <= en; k++) {
                if (jmp && k == d) continue;
                any[i][ (j * 10 + k) % m ] += any[i - 1][j];
            }
        }

        for (j = 0; j < m; j++)
            any[i][j] %= mod;
    }

    // ---------------------------------------

    any2[0][0] = 1;

    any2[1][d % m] = 1;
    for (i = 2; i <= n; i++) {
        bg = (i % 2 == 1 ? d : 0);
        en = (i % 2 == 1 ? d : 9);
        bool jmp = (i % 2 == 0);

        for (j = 0; j < m; j++) {
            if (any2[i - 1][j] == 0) continue;

            for (k = bg; k <= en; k++) {
                if (jmp && k == d) continue;
                any2[i][ (j * 10 + k) % m ] += any2[i - 1][j];
                any2[i][ (j * 10 + k) % m ] %= mod;
            }
        }

        for (j = 0; j < m; j++)
            any2[i][j] %= mod;
    }

    // ---------------------------------------------
    poww[0] = 1;
    for (i = 1; i <= n; i++)
        poww[i] = (poww[i - 1] * 10) % m;
}

ll solve(char *nr) {
    ll val = 0, aux;
    int i, j, bg, en;
    bool jmp;
    ll ans = 0;

    for (i = 1; i <= n; i++) {
        bg = (i % 2 == 0 ? d : 0);
        en = (i % 2 == 0 ? d : 9);
        if (i == 1) bg = 1;
        jmp = (i % 2 == 1);

        for (j = bg; j < nr[i] - '0' && j <= en; j++) {
            if (jmp && j == d) continue;

            aux = (val * 10 + j) % m;
            aux = (aux * poww[n - i]) % m;
            aux = (aux == 0 ? 0 : m - aux);

            ans += (i % 2 == 0 ? any[n - i][aux] : any2[n - i][aux]);
            if (ans >= mod) ans -= mod;
        }

        if (i % 2 == 0 && nr[i] - '0' != d) return ans;
        if (i % 2 == 1 && nr[i] - '0' == d) return ans;
        val = (val * 10 + nr[i] - '0') % m;
    }

    return ans;
}

bool check(char *nr) {
    ll val = 0;
    int i;

    for (i = 1; i <= n; i++)
        val = (val * 10 + nr[i] - '0') % m;

    if (val != 0) return false;

    for (i = 1; i <= n; i += 2)
        if (nr[i] - '0' == d)
            return false;

    for (i = 2; i <= n; i += 2)
        if (nr[i] - '0' != d)
            return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld %lld\n", &m, &d);
    scanf("%s\n%s", a + 1, b + 1);

    n = strlen(a + 1);

    pre();

    ans += solve(b);
    ans -= solve(a);

    if (check(b)) ans++;

    ans = (ans + 10LL * mod) % mod;

    printf("%lld", ans);

    return 0;
}