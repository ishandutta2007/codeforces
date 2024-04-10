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
    cin.tie(0);

    const int INF = 0x3f3f3f3f;

    int x = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);

    int div2Max = -INF;
    int div1Min = INF;
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
        if (A[i].second == 2) {
            div2Max = max(div2Max, x);
        } else {
            div1Min = min(div1Min, x);
        }
        x += A[i].first;
    }
    if (div2Max >= div1Min) {
        cout << "Impossible\n";
        return 0;
    }
    if (div2Max == -INF) {
        cout << "Infinity\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ans == div2Max) {
            ans = 1899;
            for (int j = i; j < n; ++j) {
                ans += A[j].first;
            }
            break;
        }
        ans += A[i].first;
    }
    cout << ans << '\n';
}