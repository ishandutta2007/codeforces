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

    int n, m;
    cin >> n >> m;

    vector<bool> used(m, false);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k-- > 0) {
            int x;
            cin >> x;
            used[x - 1] = true;
        }
    }
    bool ok = true;
    for (int i = 0; i < m; ++i)
        ok &= used[i];

    cout << (ok ? "YES": "NO") << '\n';
}