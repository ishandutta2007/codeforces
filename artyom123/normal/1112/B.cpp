#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    vector <pair<int, int>> p(k);
    vector <vector<int>> d(n);
    for (int i = 0; i < n; i++) {
        d[i].resize(a[i]);
    }
    int ind = 0;
    int m = 0;
    int now = 0;
    vector <int> t;
    int time = 0;
    while (1) {
        for (int i = 0; i < k; i++) {
            if (p[i].se == a[p[i].fi]) {
                d[p[i].fi][a[p[i].fi] - 1] = time;
                m++;
                p[i].fi = 0;
                p[i].se = 0;
                now--;
                continue;
            }
        }
        for (int i = 0; i < k; i++) {

            if (p[i].se == 0 && ind == n) {
                continue;
            }
            if (p[i].se == 0 && ind < n) {
                p[i].fi = ind;
                p[i].se = 1;
                ind++;
                now++;
                continue;
            }
            d[p[i].fi][p[i].se - 1] = time;
            p[i].se++;
        }
        t.push_back(m);
        time++;
        if (now == 0) {
            break;
        }
    }
    vector <int> usd(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d[i].size(); j++) {
            int l = int(100.00 * double(t[d[i][j] - 1]) / n + 0.5);
            if (l == j + 1) {
                usd[i] = 1;
            }
        }
    }
    int ans = 0;
    for (auto &c : usd) {
        ans += c;
    }
    cout << ans;
    return 0;
}