#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
#ifdef BZ
    freopen("../a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, zap;
    cin >> n >> zap;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<vector<int>> q(17, vector<int>(n + 1));
    {
        int cur = n - 1;
        map<int, int> g;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i];
            for (int j = 2; j * j <= x; j++)
            if (x % j == 0) {
                if (g.find(j) != g.end())
                    cur = min(cur, g[j] - 1);
                g[j] = i;
                while (x % j == 0)
                    x /= j;
            }
            if (x > 1) {
                if (g.find(x) != g.end())
                    cur = min(cur, g[x] - 1);
                g[x] = i;
            }
            q[0][i] = cur + 1;
        }
        q[0][n] = n;
        for (int j = 1; j < 17; j++)
            for (int i = 0; i <= n; i++)
                q[j][i] = q[j - 1][q[j - 1][i]];
    }
    while (zap--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int w = 0;
        for (int i = 16; i >= 0; i--)
            if (q[i][l] <= r) {
                w += (1 << i);
                l = q[i][l];
            }
        w++;
        cout << w << '\n';
    }
}