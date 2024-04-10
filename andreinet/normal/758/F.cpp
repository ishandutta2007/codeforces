#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 10'000'005;

int firstDiv[NMAX];
int primes[NMAX];
int sums[NMAX];
int cnt = 0;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    if (n > 25) {
        cout << "0\n";
        return 0;
    }
    if (n == 1) {
        cout << (r - l + 1) << '\n';
        return 0;
    }

    firstDiv[1] = 1;
    for (int i = 2; i <= r; ++i) {
        if (firstDiv[i] == 0) {
            firstDiv[i] = i;
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] <= r &&
                primes[j] <= firstDiv[i]; ++j) {
            firstDiv[i * primes[j]] = primes[j];
        }
    }

    for (int i = 1; i <= r; ++i) {
        int x = i;
        sums[i] = 1;
        while (x != 1) {
            int p = firstDiv[x];
            int k = 0;
            while (x % p == 0) {
                x /= p;
                k++;
            }
            if (k % (n - 1) != 0) {
                sums[i] = 0;
                break;
            }
        }
        sums[i] += sums[i - 1];
    }
    int64_t ans = 0;
    for (int i = l; i <= r; ++i) {
        int x = i;
        int xdv = 1;
        while (x != 1) {
            int p = firstDiv[x];
            int k = 0;
            while (x % p == 0) {
                x /= p;
                k++;
            }
            int l = k % (n - 1);
            for (int j = 0; j < l; ++j) {
                xdv *= p;
            }
        }
        int down = max(1, (l + xdv - 1) / xdv);
        int up = (i - 1) / xdv;
        ans += max(0, sums[up] - sums[down - 1]);
    }
    ans *= 2;
    cout << ans << '\n';
}