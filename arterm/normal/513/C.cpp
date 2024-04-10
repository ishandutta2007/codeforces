#include <bits/stdc++.h>

using namespace std;

const int M = 10100;
const int N = 35;

long double d[M][N], d2[M][N], sum[M][N];
int msk[M], k[N];
int n, l[N], r[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    for (int j = 0; j < n; ++j)
        for (int i = l[j]; i <= r[j]; ++i)
            msk[i] |= (1 << j);
}

int cont(int t, int x) {
    if (r[t] <= x)
        return 0;
    if (l[t] <= x)
        return r[t] - x;
    return r[t] - l[t] + 1;
}

void din() {
    sum[0][0] = 1;
    for (int i = 1; i < M; ++i)
        for (int mask = 0; mask < (1 << n); ++mask) {

            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                if ((submask & msk[i]) == submask)
                    d[i][mask] += sum[i - 1][mask ^ submask];
                if (__builtin_popcount(submask) >= 2 && (submask & msk[i]) == submask)
                    d2[i][mask] += sum[i - 1][mask ^ submask];
            }

            sum[i][mask] = sum[i - 1][mask] + d[i][mask];
        }

    long double ans = 0, den = 1;
    for (int i = 0; i < n; ++i)
        den *= r[i] - l[i] + 1;

    int tot = (1 << n) - 1;

    for (int i = 0; i < n; ++i)
        k[i] = tot ^ (1 << i);

    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < n; ++j)
            ans += 1.0 * i * d[i][k[j]] * cont(j, i) / den;
        ans += 1.0 * d2[i][tot] * i / den;
    }

    cout << ans << "\n";
}

int main() {
    cout.precision(12);
    cout << fixed;
    read();
    din();
    return 0;
}