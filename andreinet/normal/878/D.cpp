#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int KMAX = 12;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    vector<bitset<1 << KMAX>> a(k);
    for (int i = 0; i < k; ++i) {
        for (int conf = 0; conf < (1 << k); ++conf) {
            if (conf & (1 << i)) {
                a[i][conf] = 1;
            }
        }
    }
    vector<vector<int>> values(k, vector<int>(n));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> values[i][j];
        }
    }

    while (q-- > 0) {
        int type, x, y;
        cin >> type >> x >> y;
        x--; y--;
        if (type == 1) {
            a.push_back(a[x] | a[y]);
        } else if (type == 2) {
            a.push_back(a[x] & a[y]);
        } else {
            int val = 0;
            for (int step = (1 << 29); step > 0; step /= 2) {
                int nVal = val + step;
                int conf = 0;
                for (int i = 0; i < k; ++i) {
                    if (values[i][y] > nVal) {
                        conf |= 1 << i;
                    }
                }
                if (a[x][conf]) {
                    val += step;
                }
            }
            cout << val + 1 << '\n';
        }
    }
}