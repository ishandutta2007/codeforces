#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int Nmax = 105;

i64 A[Nmax][Nmax];
i64 valuesa[Nmax], valuesb[Nmax];

i64 gcd(i64 a, i64 b) {
    i64 c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> A[i][j];

    for (int i = 1; i <= M; ++i)
        valuesb[i] = A[1][i];
    for (int i = 2; i <= N; ++i)
        valuesa[i] = A[i][1] - valuesb[1];


    i64 ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
             ans = gcd(ans, abs(valuesa[i] + valuesb[j] - A[i][j]));
        }
    }

    if (ans == 0) ans = 2e9 + 7;
    for (int i = 1; i <= N; ++i)
        if (valuesa[i] < 0)
            valuesa[i] = ans + valuesa[i] % ans;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if ((valuesa[i] + valuesb[j]) % ans != A[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    cout << ans << '\n';
    for (int i = 1; i <= N; ++i) cout << valuesa[i] << " \n"[i == N];
    for (int i = 1; i <= M; ++i) cout << valuesb[i] << " \n"[i == M];
}