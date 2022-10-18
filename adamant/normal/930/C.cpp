#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 42;

int mx[4 * maxn][2];

int get(int a, int b, int z, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return mx[v][z];
    } else if(r <= a || b <= l) {
        return 0;
    } else {
        int m = (l + r) / 2;
        return max(get(a, b, z, 2 * v, l, m), get(a, b, z, 2 * v + 1, m, r));
    }
}

void upd(int p, int c, int z, int v = 1, int l = 0, int r = maxn) {
    mx[v][z] = max(mx[v][z], c);
    if(r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    if(p < m) {
        upd(p, c, z, 2 * v, l, m);
    } else {
        upd(p, c, z, 2 * v + 1, m, r);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int l[n], r[n];
    int op[m], cl[m];
    memset(op, 0, sizeof(op));
    memset(cl, 0, sizeof(cl));
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        op[l[i]]++;
        cl[r[i]]--;
    }
    int a[m];
    int cur = 0;
    for(int i = 0; i < m; i++) {
        cur += op[i];
        a[i] = cur;
        cur += cl[i];
        int A = get(0, a[i] + 1, 0);
        int B = max(get(a[i], maxn, 1), A);
        upd(a[i], A + 1, 0);
        upd(a[i], B + 1, 1);
    }
    cout << get(0, maxn, 1) << endl;
    return 0;
}