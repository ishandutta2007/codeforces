#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int64_t n, a, b, c;
    cin >> n >> a >> b >> c;

    int64_t c1 = n / a;
    int64_t c2 = max((int64_t) 0, (n - b) / (b - c));
    n -= c2 * (b - c);
    while (n >= b) {
        n = n - b + c;
        c2++;
    }
    c2 += n / a;

    cout << max(c1, c2) << '\n';
}