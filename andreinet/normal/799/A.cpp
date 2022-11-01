#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int time1 = (n + k - 1) / k * t;
    int time2 = 0x3f3f3f3f;
    for (int i = 0; i <= n; ++i) {
        int ctime = max((i + k - 1) / k * t,
                (n - i + k - 1) / k * t + d);
        time2 = min(time2, ctime);
    }
    if (time2 < time1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}