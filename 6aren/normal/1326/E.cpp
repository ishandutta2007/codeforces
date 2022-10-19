#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())
#define lc (2 * k)
#define rc (2 * k + 1)
#define mid ((l + r) / 2)

const int N = 300005;

int it[4 * N], lazy[4 * N];

void down(int k) {
    int val = lazy[k];
    if (val == 0) return;
    it[lc] += val;
    lazy[lc] += val;
    it[rc] += val;
    lazy[rc] += val;
    lazy[k] = 0;
}

void update(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        it[k] += val;
        lazy[k] += val;
        return;
    }
    down(k);
    update(lc, l, mid, u, v, val);
    update(rc, mid + 1, r, u, v, val);
    it[k] = max(it[lc], it[rc]);
}

// int get(int k, int l, int r, int id) {
//     if (l == r) return it[k];
//     down(k);
//     if (id > mid) return get(rc, mid + 1, r, id);
//     else return get(lc, l, mid, id);
// }

int p[N], pos[N], q[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    // freopen("a.txt", "r", stdin);
    // freopen("c.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    int curAns = n;
    update(1, 1, n, 1, pos[n], 1);
    for (int i = 1; i <= n; i++) {
        while (it[1] <= 0) {
            curAns--;   
            update(1, 1, n, 1, pos[curAns], 1);
        }
        cout << curAns << ' ';
        update(1, 1, n, 1, q[i], -1);
    }
    // int que;
    // cin >> que;
    // for (int i = 1; i <= que; i++) {
    //     int l, r, val;
    //     cin >> l >> r >> val;
    //     update(1, 1, n, l, r, val);
    //     get(1, 1, n, 1);
    //     for (int k = 1; k <= 13; k++) {
    //         cout << k << ' ' << it[k] << ' ' << lazy[k] << endl;
    //     }
    //     cout << endl;
    // }
    return 0;
}