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

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    auto abs = [](int a) -> int {
        return a < 0 ? -a: a;
    };

    if (n == 1) {
        cout << "-1\n";
    } else if (n == 2) {
        if (x[0] != x[1] && y[0] != y[1])
            cout << abs(x[0] - x[1]) * abs(y[0] - y[1]) << '\n';
        else 
            cout << "-1\n";
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (x[i] != x[j] && y[i] != y[j]) {
                    cout << abs(x[i] - x[j]) * abs(y[i] - y[j]) << '\n';
                    goto FINISH;
                }
            }
        }
        FINISH:;
    }
}