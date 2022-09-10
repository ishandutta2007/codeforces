#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 998'244'353;
const vector <char> brackets = {'(', ')'};

int n;
char in[N];
int pref[2][N];

int rv[N];
int sil[N];

int fast(int a, int b)
{
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = 1LL * ret * a % MOD;
        }

        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return ret;
}

int newton(int a, int b)
{
    if (b < 0 || a < b) {
        return 0;
    }

    return 1LL * sil[a] * rv[b] % MOD * rv[a - b] % MOD;
}

int main()
{
    scanf("%s", in + 1);
    n = strlen(in + 1);

    sil[0] = 1;
    for (int i = 1; i <= n; ++i) {
        sil[i] = 1LL * sil[i - 1] * i % MOD;
    }

    rv[n] = fast(sil[n], MOD - 2);
    for (int i = n; i; --i) {
        rv[i - 1] = 1LL * rv[i] * i % MOD;
    }

    int count_qm = 0;
    for (int i = 1; i <= n; ++i) {
        count_qm += in[i] == '?';
    }

    for (int t = 0; t < 2; ++t) {
        if (t > count_qm) {
            continue;
        }

        pref[t][0] = 1;
        for (int i = 1; i <= n; ++i) {
            pref[t][i] = newton(count_qm - t, i) + pref[t][i - 1];
            if (pref[t][i] >= MOD) pref[t][i] -= MOD;
        }
    }

    int suf_qm = count_qm, suf_cb = 0, pref_ob = 0;
    for (int i = 1; i <= n; ++i) {
        suf_cb += in[i] == ')';
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        suf_cb -= in[i] == ')';
        suf_qm -= in[i] == '?';

        if (in[i] == ')') {
            continue;
        }

        if (suf_cb + suf_qm > pref_ob) {
            ans += pref[in[i] == '?'][suf_cb + suf_qm - pref_ob - 1];
        }

        pref_ob += in[i] == '(';
    }

    printf("%lld\n", ans % MOD);
    return 0;
}