#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 gjsldkgfsdg
const int maxN = 2 * (int)1e5 + 100;
int n, m, k, q;
vector < pair < int, int > > t[2 * maxN];
vector < pair < int, int > > merge(vector < pair < int, int > >& a, vector < pair < int, int > >& b) {
    vector < pair < int, int > > c;
    int mx = 0;
    int l = 0;
    int r = 0;
    while (true) {
        int what = -1;
        if (l == a.size() && r == b.size()) return c;
        if (l == a.size()) {
            what = 1;
        }
        else if (r == b.size()) {
            what = 0;
        }
        else {
            if (a[l].first < b[r].first) what = 0;
            else if (a[l].first > b[r].first) what = 1;
            else {
                if (a[l].second < b[r].second) what = 1;
                else what = 0;
            }
        }
        if (what == 0) {
            if (mx >= a[l].second) {

            }
            else {
                mx = max(mx, a[l].second);
                c.push_back(a[l]);
            }
            l++;
        }
        else {
            if (mx >= b[r].second) {

            }
            else {
                mx = max(mx, b[r].second);
                c.push_back(b[r]);
            }
            r++;
        }
    }
}
int x1[2 * maxN], y1[2 * maxN], x2[2 * maxN], y2[2 * maxN];
int posX[2 * maxN], posY[2 * maxN];
bool ok[2 * maxN];
vector < int > byX[2 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        for (int i = 0; i + 1 < byX[tl].size(); i++) {
            if (byX[tl][i] + 1 <= byX[tl][i + 1] - 1) {
                t[v].emplace_back(byX[tl][i] + 1, byX[tl][i + 1] - 1);
            }
        }
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = merge(t[v + v], t[v + v + 1]);
}
bool ask(int v, int tl, int tr, int l, int r, int x, int y) {
    if (tl == l && tr == r) {
        if (t[v].empty()) return true;
        if (t[v].back().second < y) return true;
        if (t[v][0].first > x) return true;
        auto it = lower_bound(t[v].begin(), t[v].end(), make_pair(x + 1, -1)) - t[v].begin();
        it--;
        if (it < 0 || it >= t[v].size()) return true;
        return (!(t[v][it].first <= x && y <= t[v][it].second));
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) return ask(v + v, tl, tm, l, r, x, y);
    else if (l > tm) return ask(v + v + 1, tm + 1, tr, l, r, x, y);
    else return (ask(v + v, tl, tm, l, tm, x, y) && ask(v + v + 1, tm + 1, tr, tm + 1, r, x, y));
}
void solve() {
    for (int i = 1; i <= 4 * n; i++) {
        t[i].clear();
        byX[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        byX[i].push_back(0);
    }
    for (int i = 1; i <= k; i++) {
        byX[posX[i]].push_back(posY[i]);
    }
    for (int i = 1; i <= n; i++) {
        byX[i].push_back(m + 1);
    }
    for (int i = 1; i <= n; i++) {
        sort(byX[i].begin(), byX[i].end());
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        bool hs = ask(1, 1, n, x1[i], x2[i], y1[i], y2[i]);
        ok[i] |= hs;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++) {
        cin >> posX[i] >> posY[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    solve();
    swap(n, m);
    for (int i = 1; i <= k; i++) {
        swap(posX[i], posY[i]);
    }
    for (int i = 1; i <= q; i++) {
        swap(x1[i], y1[i]);
        swap(x2[i], y2[i]);
    }
    solve();
    for (int i = 1; i <= q; i++) {
        if (ok[i]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}