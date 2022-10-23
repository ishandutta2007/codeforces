#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
int pw[N];
int good_right[N];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void sub(int &a, int b)
{
    a -= b;
    if (a < 0) {
        a += MOD;
    }
}

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

void solve()
{
    scanf("%d", &n);

    int sum = 0;
    for (int i = n; i > n / 2; --i) {
        good_right[i] = i == n ? 2 : pw[n - i];
        add(sum, good_right[i]);
    }

    int ptr = n;
    for (int i = n / 2; i >= 1; --i) {
        while (ptr >= i + i) {
            sub(sum, good_right[ptr--]);
        }

        good_right[i] = sum;
        add(sum, good_right[i]);
    }

    int rv = fast(pw[n], MOD - 2);
    for (int i = 1; i <= n; ++i) {
        int ans = 1LL * good_right[i] * pw[i / 2] % MOD;
        printf("%lld\n", 1LL * ans * rv % MOD);
    }
}

int main()
{
    pw[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = 2 * pw[i - 1];
        if (pw[i] >= MOD) {
            pw[i] -= MOD;
        }
    }

    int cases = 1;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}