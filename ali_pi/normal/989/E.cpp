#include <bits/stdc++.h>

using namespace std;

int n;
int x[205], y[205];
double f[205][205][15];
double prob[205], save[205];
vector <vector <int> > lines;

pair <int, int> fix(pair <int, int> a) {
    if (a.second == 0) return pair <int, int> (1, 0);
    int d = __gcd(a.first, a.second);
    a.first /= d, a.second /= d;
    if (a.second < 0) a.first *= -1, a.second *= -1;
    return a;
}

void build(int r) {
    map <pair <int, int>, vector <int> > cnt;
    for (int i = 0; i < n; ++i) if (i != r) {
        int xx = x[i] - x[r], yy = y[i] - y[r];
        cnt[fix(make_pair(xx, yy))].push_back(i);
    }
    int sz = cnt.size();
    for (auto u: cnt) {
        u.second.push_back(r);
        int flag = 1;
        for (auto v: u.second) {
            f[r][v][0] += 1.0 / u.second.size() / sz;
            if (v < r) flag = 0;
        }
        if (flag) lines.push_back(u.second);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i)
        build(i);
    for (int d = 1; d < 15; ++d) {
        for (int i = 0; i < n; ++i)
             for (int j = 0; j < n; ++j)
                 for (int k = 0; k < n; ++k) {
                      f[i][k][d] += f[i][j][d-1] * f[j][k][d-1];
        }
    }
    int q; cin >> q;
    cout << setprecision(10) << fixed;
    while (q--) {
        int t, m; cin >> t >> m; 
        --t; --m;
        for (int i = 0; i < n; ++i) 
            prob[i] = 0;
        prob[t] = 1;
        for (int d = 0; d < 15; ++d) 
            if (m >> d & 1) {
            for (int i = 0; i < n; ++i) 
                save[i] = prob[i], prob[i] = 0;
            for (int i = 0; i < n; ++i) 
                 for (int j = 0; j < n; ++j) 
                      prob[i] += save[j] * f[i][j][d];
        }
        double ans = 0;
        for (auto line: lines) {
            double opt = 0;
            for (auto u: line) 
                opt += prob[u];
            ans = max(ans, opt / line.size());
        }
        cout << ans << '\n';
    }
}