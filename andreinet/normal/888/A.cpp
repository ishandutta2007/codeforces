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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& p: a) {
        cin >> p;
    }
    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if ((a[i] < a[i - 1] && a[i] < a[i + 1]) ||
                (a[i] > a[i - 1] && a[i] > a[i + 1])) {
            ans++;
        }
    }
    cout << ans << '\n';
}