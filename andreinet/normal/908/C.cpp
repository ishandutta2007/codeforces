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

    int n, r;
    cin >> n >> r;

    vector<int> x(n);
    vector<double> y(n);
    cout << setprecision(9) << fixed;
    for (int i = 0; i < n; ++i) {
        int cx;
        double cy = r;
        cin >> cx;
        x[i] = cx;
        for (int j = 0; j < i; ++j) {
            if (abs(x[i] - x[j]) > 2 * r) {
                continue;
            }
            double vy = 4.0 * r * r - (x[i] - x[j]) * (x[i] - x[j]);
            vy = sqrt(vy) + y[j];
            cy = max(cy, vy);
        }
        y[i] = cy;
        cout << cy << ' ';
    }
    cout << '\n';
}