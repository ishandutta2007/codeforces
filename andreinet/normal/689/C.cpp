#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int64_t pw3(int64_t x) {
    return x * x * x;
}

int64_t check(int64_t n) {
    int64_t ans = 0;
    for (int i = 2; pw3(i) <= n; ++i) {
        ans += n / pw3(i);
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t m;
    cin >> m;

    int64_t n = 0;
    for (int64_t step = 1LL << 60; step > 0; step /= 2) {
        if (check(n + step) < m) {
            n += step;
        }
    }
    ++n;
    if (check(n) == m) {
        cout << n << '\n';
    } else {
        cout << "-1\n";
    }
}