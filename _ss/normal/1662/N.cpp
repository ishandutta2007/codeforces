#include <bits/stdc++.h>
using namespace std;

const int N = 1510;

int n, a[N][N], x[N * N], y[N * N], u;

struct BIT {
    int d[N];

    void update(int x) {
        for (; x < N; x += x & -x) {
            ++d[x];
        }
    }
    int get(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res += d[x];
        }
        return res;
    }
} row[N], col[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            x[a[i][j]] = i;
            y[a[i][j]] = j;
        }
    }

    long long cnt = 0;
    for (int val = 1; val <= n * n; ++val) {
        int u = col[y[val]].get(x[val]);
        int d = col[y[val]].get(n) - u;
        int l = row[x[val]].get(y[val]);
        int r = row[x[val]].get(n) - l;
        for (int i = 0; i < 2; ++i) {
            cnt += u * l + u * r + d * l + d * r;
            u = (x[val] - 1) - u;
            d = (n - x[val]) - d;
            l = (y[val] - 1) - l;
            r = (n - y[val]) - r;
        }
        row[x[val]].update(y[val]);
        col[y[val]].update(x[val]);
    }

    long long numRect = 1ll * n * (n - 1) / 2 * n * (n - 1) / 2;
    cout << (4 * numRect - cnt) / 2 << '\n';

    return 0;
}