#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 200005;

int it[4 * N];
int lastApp[N];

struct Rec {
    int x, y, xx, yy, id;
    Rec() {}
    Rec(int x, int y, int xx, int yy, int id) : x(x), y(y), xx(xx), yy(yy), id(id) {}
};

void update(int k, int l, int r, int id, int val) {
    if (l > id || r < id) return;
    if (l == r && l == id) {
        it[k] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * k, l, mid, id, val);
    update(2 * k + 1, mid + 1, r, id, val);
    it[k] = min(it[2 * k], it[2 * k + 1]);
}

int get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 1e9;
    if (l >= u && r <= v) return it[k];
    int mid = (l + r) / 2;
    int g1 = get(2 * k, l, mid, u, v);
    int g2 = get(2 * k + 1, mid + 1, r, u, v);
    return min(g1, g2);
}

int n, m, k, q;
Rec rec[N];
ii rock[N];
bool ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++) {
        cin >> rock[i].x >> rock[i].y;
    }
    for (int i = 1; i <= q; i++) {
        cin >> rec[i].x >> rec[i].y >> rec[i].xx >> rec[i].yy;
        rec[i].id = i;
    }
    sort(rec + 1, rec + q + 1, [](Rec x, Rec y) {
        return x.yy < y.yy;
    });
    sort(rock + 1, rock + k + 1, [](ii x, ii y) {
        return x.y < y.y;
    });
    int cur = 1;
    for (int i = 1; i <= q; i++) {
        while (cur <= k && rock[cur].y <= rec[i].yy) {
            update(1, 1, n, rock[cur].x, rock[cur].y);
            cur++;
        }
        int foo = get(1, 1, n, rec[i].x, rec[i].xx);
        if (foo >= rec[i].y) ans[rec[i].id] = 1;
    }
    sort(rec + 1, rec + q + 1, [](Rec x, Rec y) {
        return x.xx < y.xx;
    });
    sort(rock + 1, rock + k + 1);
    memset(it, 0, sizeof(it));
    cur = 1;
    for (int i = 1; i <= q; i++) {
        while (cur <= k && rock[cur].x <= rec[i].xx) {
            update(1, 1, m, rock[cur].y, rock[cur].x);
            cur++;
        }
        int foo = get(1, 1, m, rec[i].y, rec[i].yy);
        if (foo >= rec[i].x) ans[rec[i].id] = 1;
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}