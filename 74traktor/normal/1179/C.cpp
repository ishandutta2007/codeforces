#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 1;
int a[300005];
int b[300005];
int tree[4 * maxn];
int psh[4 * maxn];

inline void push(int i, int len){
    tree[i] += psh[i];
    if (len != 1) psh[2 * i + 1] += psh[i], psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int dx){
    push(i, r - l);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq){
        psh[i] += dx;
        push(i, r - l);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, dx);
    update(2 * i + 2, m, r, lq, rq, dx);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int get_ans(int i, int l, int r){
    push(i, r - l);
    if (r - l == 1) return l;
    int m = (r + l) / 2;
    if (tree[2 * i + 2] + psh[2 * i + 2] > 0) return get_ans(2 * i + 2, m, r);
    else return get_ans(2 * i + 1, l, m);
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    multiset < int > Q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        Q.insert(a[i]);
        update(0, 1, maxn, 1, a[i] + 1, 1);
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
        update(0, 1, maxn, 1, b[i] + 1, -1);
    }
    int q, t, pos, x;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> t >> pos >> x;
        if (t == 1){
            update(0, 1, maxn, 1, a[pos] + 1, -1);
            Q.erase(Q.find(a[pos]));
            a[pos] = x;
            Q.insert(a[pos]);
            update(0, 1, maxn, 1, a[pos] + 1, 1);
        }
        else{
            update(0, 1, maxn, 1, b[pos] + 1, 1);
            b[pos] = x;
            update(0, 1, maxn, 1, b[pos] + 1, -1);
        }
        if (tree[0] > 0){
            auto it = Q.upper_bound(get_ans(0, 1, maxn));
            it--;
            cout << (*it) << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}