#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
#define int long long
const int n = 2e5 + 10;

struct node {
    int cnt = 0, sum1 = 0, sum2 = 0, p = 0;
};

vector <node> t;

inline void push(int v) {
    t[2 * v].sum2 += t[2 * v].cnt * t[v].p * t[v].p + 2 * t[2 * v].sum1 * t[v].p;
    t[2 * v + 1].sum2 += t[2 * v + 1].cnt * t[v].p * t[v].p + 2 * t[2 * v + 1].sum1 * t[v].p;
    t[2 * v].sum1 += t[2 * v].cnt * t[v].p;
    t[2 * v + 1].sum1 += t[2 * v + 1].cnt * t[v].p;
    t[2 * v].p += t[v].p;
    t[2 * v + 1].p += t[v].p;
    t[v].p = 0;
}

inline node merge(node a, node b) {
    node ans;
    ans.cnt = a.cnt + b.cnt;
    ans.sum1 = a.sum1 + b.sum1;
    ans.sum2 = a.sum2 + b.sum2;
    return ans;
}

void add(int v, int l, int r, int i, int x) {
    if (l > i || i > r) return;
    if (l == r) {
        t[v].cnt = 1;
        t[v].sum1 = x;
        t[v].sum2 = x * x;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    add(2 * v, l, m, i, x);
    add(2 * v + 1, m + 1, r, i, x);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void del(int v, int l, int r, int i) {
    if (l > i || i > r) return;
    if (l == r) {
        t[v].cnt = 0;
        t[v].sum1 = 0;
        t[v].sum2 = 0;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    del(2 * v, l, m, i);
    del(2 * v + 1, m + 1, r, i);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

node get_seg(int v, int l, int r, int A, int B) {
    if (l > B || A > r) return node();
    if (A <= l && r <= B) return t[v];
    push(v);
    int m = (l + r) / 2;
    return merge(get_seg(2 * v, l, m, A, B), get_seg(2 * v + 1, m + 1, r, A, B));
}

void update(int v, int l, int r, int A, int B, int x) {
    if (l > B || A > r) return;
    if (A <= l && r <= B) {
        t[v].sum2 += x * x * t[v].cnt + 2 * x * t[v].sum1;
        t[v].sum1 += t[v].cnt * x;
        t[v].p += x;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    update(2 * v, l, m, A, B, x);
    update(2 * v + 1, m + 1, r, A, B, x);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int q, d;
    cin >> q >> d;
    t.resize(4 * n);
    set <int> s;
    s.insert(2 * n);
    while (q--) {
        int x;
        cin >> x;
        if (s.count(x)) {
            del(1, 0, n - 1, x);
            s.erase(x);
            update(1, 0, n - 1, x - d, x - 1, -1);
        } else {
            int right_bad = *s.upper_bound(x + d);
            add(1, 0, n - 1, x, get_seg(1, 0, n - 1, x, right_bad - 1).cnt);
            update(1, 0, n - 1, x - d, x - 1, 1);
            s.insert(x);
        }
        cout << (t[1].sum2 - t[1].sum1) / 2 << "\n";
    }
}

/*

 */