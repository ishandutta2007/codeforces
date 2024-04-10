#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

int n, a[M], l[M], r[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = n; i >= 1; --i) {
        l[i] = min(l[i + 1] + 1, a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        r[i] = min(r[i - 1] + 1, a[i]);
    }

    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, min(l[i], r[i]));

    cout << ans << "\n";

    return 0;
}