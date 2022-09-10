#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 1'000'007;
const int MOD = 998'244'353;

int n;
int in[N], cnt[N];
int sil[N], rev_sil[N];

int gcd_elem;
vector <int> elems;

int mem_perm[N];
int mem_result[N];

int fast(int a, int b) {
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

void clear()
{
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
    }

    gcd_elem = 0;
    elems.clear();
}

void solve()
{
    scanf("%d", &n);
    clear();

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        cnt[in[i]]++;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            gcd_elem = gcd(gcd_elem, cnt[i]);
            elems.push_back(i);
        }
    }

    if (elems.size() == 1) {
        puts("1");
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0 && gcd_elem % (n / i) == 0) {
            mem_perm[i] = sil[i];
            for (auto v: elems) {
                mem_perm[i] = 1LL * mem_perm[i] * rev_sil[cnt[v] / (n / i)] % MOD;
            }

            LL mult = 0, pref = 0;
            for (auto v: elems) {
                mult += cnt[v] / (n / i) * pref;
                pref += cnt[v] / (n / i);
            }

            mult *= 2 * n;
            mult %= MOD;
            mem_result[i] = mem_perm[i] * mult % MOD * sil[i - 2] % MOD * rev_sil[i] % MOD;
        } else {
            mem_perm[i] = mem_result[i] = 0;
        }
    }

    long long sum_perm = 0, sum_all = 0;
    for (int i = 1; i <= n; ++i) {
        sum_perm += mem_perm[gcd(n, i)];
        sum_all += mem_result[gcd(n, i)];
    }

    sum_perm %= MOD, sum_all %= MOD;
    printf("%lld\n", 1LL * sum_all * fast(sum_perm, MOD - 2) % MOD);
}

int main()
{
    sil[0] = 1;
    for (int i = 1; i < N; ++i) {
        sil[i] = 1LL * sil[i - 1] * i % MOD;
    }

    rev_sil[N - 1] = fast(sil[N - 1], MOD - 2);
    for (int i = N - 1; i; --i) {
        rev_sil[i - 1] = 1LL * rev_sil[i] * i % MOD;
    }

    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}