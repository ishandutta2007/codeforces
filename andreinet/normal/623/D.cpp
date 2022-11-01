#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
typedef long double ldouble;
const int NMAX = 105;

ldouble P[NMAX];
ldouble notCatch[NMAX];
ldouble Pleft[NMAX], Pright[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ldouble ans = n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        P[i] = (ldouble) x / 100;

        notCatch[i] = 1 - P[i];
        ans *= P[i];
    }

    for (int i = n + 1; i <= 500000; ++i) {
        Pleft[0] = 1;
        for (int j = 1; j <= n; ++j) {
            Pleft[j] = Pleft[j - 1] * (1 - notCatch[j]);
        }
        Pright[n + 1] = 1;
        for (int j = n; j > 0; --j) {
            Pright[j] = Pright[j + 1] * (1 - notCatch[j]);
        }
        int pos = 0;
        ldouble mx = 0;
        for (int j = 1; j <= n; ++j) {
            ldouble pc = Pleft[j - 1] * Pright[j + 1] * notCatch[j] * P[j];
            if (pc > mx) {
                pos = j;
                mx = pc;
            }
        }

        ans += mx * i;
        notCatch[pos] *= (1 - P[pos]);
    }

    cout << setprecision(17) << fixed;
    cout << ans << '\n';
}