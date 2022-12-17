#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> a(n);
    for (auto &[x, w, c] : a) {
        cin >> x >> w >> c;
    }
    sort(a.begin(), a.end());
    vector<double> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = -get<1>(a[i]);
        for (int j = 0; j < i; j++) {
            f[i] = max(f[i], f[j] - get<1>(a[i]) + 0.005 * k * (get<2>(a[i]) + get<2>(a[j]))
                * (get<0>(a[i]) - get<0>(a[j])));
        }
    }
    double ans = *max_element(f.begin(), f.end());
    ans = max<double>(0, ans);
    cout << fixed << setprecision(9) << ans << "\n";
    return 0;
}