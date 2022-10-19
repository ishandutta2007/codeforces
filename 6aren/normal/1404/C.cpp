#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)\

const int N = 300005;

int n, q, a[N];


int it[4 * N];
int lazy[4 * N];
int bit[N];

void bupdate(int k) {
    for (int i = k; i <= n; i += (i & (-i))) bit[i]++;
}

int get(int k) {
    int res = 0;
    for (int i = k; i > 0; i -= (i & (-i))) res += bit[i];
    return res;
}

void build(int k, int l, int r) {
    if (l == r) {
        it[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    it[k] = max(it[2 * k], it[2 * k + 1]);
}

void down(int k) {
    int val = lazy[k];
    if (val == 0) return;
    it[2 * k] += val;
    it[2 * k + 1] += val;
    lazy[2 * k] += val;
    lazy[2 * k + 1] += val;
    lazy[k] = 0;
    return;
}


void update(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        it[k] += val;
        lazy[k] += val;
        return;
    }
    down(k);
    int mid = (l + r) / 2;
    update(2 * k, l, mid, u, v, val);
    update(2 * k + 1, mid + 1, r, u, v, val);
    it[k] = max(it[2 * k], it[2 * k + 1]);
}

int getMx(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e9;
    if (l >= u && r <= v) return it[k];
    down(k);
    int mid = (l + r) / 2;
    return max(getMx(2 * k, l, mid, u, v), getMx(2 * k + 1, mid + 1, r, u, v));
}

int getId(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return 0;
    if (l != r) down(k);
    int mid = (l + r) / 2;
    if (l >= u && r <= v) {
        if (it[k] != val) return 0;
        if (l == r) return l;
        if (it[2 * k] == val) getId(2 * k, l, mid, u, v, val);
        else getId(2 * k + 1, mid + 1, r, u, v, val);
    } else {
        int id1 = getId(2 * k, l, mid, u, v, val);
        int id2 = getId(2 * k + 1, mid + 1, r, u, v, val);
        return max(id1, id2);
    }

}

int ans[N];


int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
        if (a[i] > 0) a[i] = -1e9;
    }

    build(1, 1, n);

    vector<pair<ii, int>> que;
    for (int i = 1; i <= q; i++) {
        pair<ii, int> u;
        cin >> u.x.x >> u.x.y;
        u.y = i;
        que.pb(u);
    }

    sort(que.rbegin(), que.rend());



    for (auto e : que) {
        int le = e.x.x;
        int ri = e.x.y;
        while (true) {
            int mx = getMx(1, 1, n, le + 1, n);
            if (mx < 0) break;
            int id = getId(1, 1, n, le + 1, n, mx);
            bupdate(id);
            update(1, 1, n, id, id, -1e9);
            update(1, 1, n, id, n, 1);
        }
        ans[e.y] = get(n - ri) - get(le);
    }


    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

    return 0;
}