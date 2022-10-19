#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

struct my_data {
    int minn, maxx, cntmn, cntmx, cnt_zero;

    my_data(int minn, int maxx, int cntmn, int cntmx, int cnt_zero) : minn(minn), maxx(maxx), cntmn(cntmn), cntmx(cntmx), cnt_zero(cnt_zero) {};

    my_data() {
        minn = 1e9;
        maxx = -1e9;
        cntmn = 0;
        cntmx = 0;
        cnt_zero = 0;
    }
};

my_data comb(my_data a, my_data b) {
    int minn, cntmn, maxx, cntmx, cnt_zero;
    if (a.minn == b.minn) {
        minn = a.minn;
        cntmn = a.cntmn + b.cntmn;
    } else if (a.minn < b.minn) {
        minn = a.minn;
        cntmn = a.cntmn;
    } else {
        minn = b.minn;
        cntmn = b.cntmn;
    }
    if (a.maxx == b.maxx) {
        maxx = a.maxx;
        cntmx = a.cntmx + b.cntmx;
    } else if (a.maxx > b.maxx) {
        maxx = a.maxx;
        cntmx = a.cntmx;
    } else {
        maxx = b.maxx;
        cntmx = b.cntmx;
    }
    cnt_zero = a.cnt_zero + b.cnt_zero;
    return my_data(minn, maxx, cntmn, cntmx, cnt_zero);
}


my_data tree[4 * MAXN];

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = my_data(1e9, -1e9, 0, 0, 1);
    } else {
        int m = l + (r - l) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        tree[v] = comb(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

void update(int v, int l, int r, int ind) {
    if (ind < l || ind >= r) {
        return;
    }
    if (l + 1 == r) {
        if (tree[v].minn == 1e9) {
            tree[v].minn = 0;
        }
        tree[v] = my_data(tree[v].minn + 1, tree[v].minn + 1, 1, 1, 0);
    } else {
        int m = l + (r - l) / 2;
        update(2 * v + 1, l, m, ind);
        update(2 * v + 2, m, r, ind);
        tree[v] = comb(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build(0, 0, MAXN);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max_x = 1;
    for (int i = 0; i < n; i++) {
        update(0, 0, MAXN, arr[i]);
        int maxx = tree[0].maxx;
        int minn = tree[0].minn;
        int cntmx = tree[0].cntmx;
        int cntmn = tree[0].cntmn;
        int cnt_zero = tree[0].cnt_zero;
        if (maxx == minn) {
            if (maxx == 1 || cntmn == 1) {
                max_x = i + 1;
            }
        } else if (((cntmx == 1 && maxx == minn + 1) || (cntmn == 1 && minn == 1)) && (cntmx + cntmn + cnt_zero == MAXN)) {
            max_x = i + 1;
        }
    }
    cout << max_x << endl;
    return 0;
}