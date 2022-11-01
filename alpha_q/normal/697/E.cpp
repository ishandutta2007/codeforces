#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INV = (1 + MOD)/3;

int k;
long long power = 1;
bool flag = 1;

long long bigMod (long long a, long long e) {
    long long r = 1LL;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        long long x;
        scanf("%I64d", &x);
        if ((x & 1) == 0) flag = 0;
        x %= (MOD - 1);
        power *= x;
        power %= (MOD - 1);
    }
    power = (power + MOD - 2) % (MOD - 1);

    long long p = bigMod(2LL, power);
    long long q = p;
    if (flag) p = (p + MOD - 1) % MOD;
    else p = (p + 1) % MOD;
    p = (p * INV) % MOD;

    printf("%I64d/%I64d\n", p, q);
    return 0;
}