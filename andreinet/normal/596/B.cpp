#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> B(n);
    for (int i = 0; i < n; ++i) cin >> B[i];

    auto abs = [](int a) -> int {
        return a < 0 ? -a: a;
    };

    int64_t ans = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(last - B[i]);
        last = B[i];
    }

    cout << ans << '\n';
}