#include <bits/stdc++.h>

#define lint long long int
using namespace std;

int raise(int a, lint b, int MOD) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1LL * a * raise(a, b - 1, MOD)) % MOD;
    else {
        int aux = raise(a, b >> 1, MOD);
        return (1LL * aux * aux) % MOD;
    }
}

const int NMAX = 100005;
const int MOD = 1000000007;
int n;
lint v[NMAX];

const int INV3 = raise(3, MOD - 2, MOD);

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    int even = false;
    int prodMOD = 1;
    int prod3 = 1;
    for (int i = 1; i <= n; ++ i) {
        if (v[i] % 2 == 0)
            even = true;
        prodMOD = (1LL * prodMOD * (v[i] % (MOD - 1))) % (MOD - 1);
        prod3 = (1LL * prod3 * (v[i] % 2)) % 2;
    }

    prodMOD --;
    if (prodMOD < 0)
        prodMOD += (MOD - 1);

    prod3 --;
    if (prod3 < 0)
        prod3 += 2;

    int rest3 = raise(2, prod3, 3);

    int numarator = raise(2, prodMOD, MOD);
    int numitor = (3LL * raise(2, prodMOD, MOD)) % MOD;

    if (even) {
        numarator = (numarator + 1) % MOD;
        rest3 = (rest3 + 1) % 3;
    }
    else {
        numarator = (numarator + MOD - 1) % MOD;
        rest3 = (rest3 + 2) % 3;
    }

    if (!rest3) {
        numarator = (1LL * INV3 * numarator) % MOD;
        numitor = (1LL * INV3 * numitor) % MOD;
    }

    cout << numarator << "/" << numitor << endl;
    return 0;
}