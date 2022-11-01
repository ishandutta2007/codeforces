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

    map<int, int> d1, d2;
    int n;
    cin >> n;

    while (n-- > 0) {
        int x, y;
        cin >> x >> y;
        d1[x + y]++;
        d2[x - y]++;
    }

    int64_t ans = 0;
    for (const auto& p: d1) {
        ans += (int64_t) p.second * (p.second - 1) / 2;
    }
    for (const auto& p: d2) {
        ans += (int64_t) p.second * (p.second - 1) / 2;
    }

    cout << ans << '\n';
}