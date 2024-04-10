#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

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
    for (int& x: a) {
        cin >> x;
    }
    int cnt1 = 0;
    for (int x: a) {
        cnt1 += x == 1;
    }
    if (cnt1 == 0) {
        int ans = 4 * n;
        for (int i = 0; i < n; ++i) {
            int val = a[i];
            int steps = 0;
            for (int j = i + 1; j < n; ++j) {
                val = gcd(val, a[j]);
                steps++;
                if (val == 1) {
                    ans = min(ans, steps + n - 1);
                    break;
                }
            }
        }
        if (ans == 4 * n) {
            ans = -1;
        }
        cout << ans << '\n';
    } else {
        cout << n - cnt1 << '\n';
    }
}