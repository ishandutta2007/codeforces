#include <bits/stdc++.h>

using namespace std;

int a[14000];
int ans[14000];

void solve() {
    int n;
    //cin >> n;
    /*n = 1000;
    int t = 0;
    for (int i = 1; i <= n / 2; ++i) a[i] = rand(), t += a[i];
    for (int i = n / 2 + 1; i < n; ++i) {
        a[i] = -1 * (rand() % t);
        t += a[i];
    }
    a[n] = -1 * t;*/
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ok = 0;
    for (int i = 1; i <= n; ++i) {
        if (abs(a[i]) % 2 == 0) ans[i] = a[i] / 2;
        else {
            if (ok == 0) {
                if (a[i] < 0) ans[i] = -1 * abs(a[i]) / 2 - 1;
                else ans[i] = a[i] / 2;
            }
            else {
                if (a[i] < 0) ans[i] = -1 * abs(a[i]) / 2;
                else ans[i] = (a[i] + 1) / 2;
            }
            ok = (ok^1);
        }
    }
    /*int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += ans[i];
        if (abs(ans[i] * 2 - a[i]) > 1) {
            cout << ans[i] << " " << a[i] << endl;
            cout << "WA" << endl;
            exit(0);
        }
    }*/
    //if (sum != 0) cout << "WA" << endl;
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << '\n';
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}