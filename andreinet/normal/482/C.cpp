#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

typedef long long i64;

const int Nmax = 55, Lmax = 22;

i64 Dp[1 << Lmax];
string S[Nmax];

template<class type>
int countBytes(type x) {
    int ret = 0;
    while (x) {
        ++ret;
        x = x & (x - 1);
    }
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, L;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> S[i];
        L = S[i].length();

        for (int j = 0; j < i; ++j) {
            int x = 0;
            for (int k = 0; k < L; ++k)
                if (S[i][k] == S[j][k])
                    x |= 1 << k;

            Dp[x] |= 1LL << i;
            Dp[x] |= 1LL << j;
        }
    }

    for (int conf = (1 << L) - 1; conf >= 0; --conf)
        for (int i = 0; i < L; ++i)
            if (!(conf & (1 << i)))
                Dp[conf] |= Dp[conf ^ (1 << i)];

    double ans = 0;
    for (int conf = (1 << L) - 2; conf >= 0; --conf) {
        int cnt = 0;
        for (int i = 0; i < L; ++i) {
            if (!(conf & (1 << i))) {
                i64 x = ~Dp[conf ^ (1 << i)] & Dp[conf];
                cnt += countBytes(x);
            }
        }

        int nr = countBytes(conf);
        double p = 1;
        for (int i = 0; i < nr; ++i)
            p *= (double) (nr - i) / (L - i);

        p /= L - nr;

        ans += p * cnt * (nr + 1);
    }

    cout << setprecision(30) << fixed;
    cout << ans / N << '\n';
}