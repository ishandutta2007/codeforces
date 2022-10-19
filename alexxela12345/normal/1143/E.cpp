//                              ___-------___
//                          _-~~             ~~-_
//                       _-~                    /~-_
//    /^\__/^\         /~  \                   /    \
//  /| O ||O |        /      \_______________/        \
// | |___||__|      /       /                \          \
// |          \    /      /                    \          \
// |   (_______) /______/                        \_________ \
// |         / /         \                      /            \
//  \         \^\\         \                  /               \     /
//    \         ||           \______________/      _-_       //\__//
//      \       ||------_-~~-_ ------------- \ --/~   ~\    || __/
//        ~-----||====/~     |==================|       |/~~~~~
//         (_(__/  ./     /                    \_\      \.
//                (_(___/                         \_____)_)
//
#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;


vector<int> arrr, tree;

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = arrr[l];
    } else {
        int m = l + (r - l) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

int query(int v, int l, int r, int ql, int qr) {
    if (qr <= l || ql >= r) {
        return 1e9;
    }
    if (ql <= l && r <= qr) {
        return tree[v];
    }
    int m = l + (r - l) / 2;
    return min(query(2 * v + 1, l, m, ql, qr), query(2 * v + 2, m, r, ql, qr));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
        perm[i]--;
    }
    vector<int> next(n), prev(n);
    for (int i = 0; i < n; i++) {
        next[perm[i]] = perm[(i + 1) % n];
        prev[next[perm[i]]] = perm[i];
    }
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    vector<vector<int>> nxt(20, vector<int> (m, 1e9));
    vector<vector<int>> cur_arr(n);
    for (int i = 0; i < m; i++) {
        int el = arr[i];
        cur_arr[el].push_back(i);
        for (int j : cur_arr[prev[el]]) {
            nxt[0][j] = i;
        }
        cur_arr[prev[el]].clear();
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < m; j++) {
            if (nxt[i - 1][j] != 1e9)
                nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
        }
    }
    vector<int> nxtt(m);
    for (int i = 0; i < m; i++) {
        nxtt[i] = i;
        int curr = n - 1;
        int p = 0;
        while (curr > 0) {
            if (curr & 1) {
                if (nxtt[i] != 1e9)
                    nxtt[i] = nxt[p][nxtt[i]];
            }
            p++;
            curr >>= 1;
        }
    }
    arrr = nxtt;
    tree.resize(4 * m);
    build(0, 0, m);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        int ans = query(0, 0, m, l, r);
        if (ans < r) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
    return 0;
}