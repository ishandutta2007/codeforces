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

    int q;
    cin >> q;

    while (q-- > 0) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> a[i][j];
            }
        }
        int64_t sum1 = 0;
        for (int j = 0; j < w; ++j) {
            sum1 += abs(a[h - 1][j] - a[0][j]);
        }
        int64_t sum2 = 0;
        for (int j = 0; j < w; ++j) {
            sum2 += abs(a[h / 2 - 1][j] - a[h / 2][j]);
        }
        if (sum1 < sum2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}