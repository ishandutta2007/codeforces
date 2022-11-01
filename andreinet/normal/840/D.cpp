#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int NMAX = 300005;
const int KV = 5;

struct Freq {
    int val, cnt;
};

Freq aint[4 * NMAX][KV];
int a[NMAX];

vector<int> valuesPos[NMAX];
vector<int> vQueries[NMAX];

class FenwickTree {
public:
    FenwickTree(int n):
        tree(vector<int>(n + 1, 0)) {}

    void update(int pos, int value) {
        for (++pos; pos < SZ(tree); pos += pos & -pos) {
            tree[pos] += value;
        }
    }

    int query(int pos) {
        int ret = 0;
        for (++pos; pos > 0; pos -= pos & -pos) {
            ret += tree[pos];
        }
        return ret;
    }
    int query(int left, int right) {
        return query(right) - query(left - 1);
    }
private:
    vector<int> tree;
};

void merge(Freq* a, Freq* b, Freq* to) {
    Freq v[2 * KV];
    int pos = KV;
    for (int i = 0; i < KV; ++i) {
        v[i] = a[i];
    }
    for (int i = 0; i < KV; ++i) {
        bool found = false;
        for (int j = 0; j < pos; ++j) {
            if (v[j].val == b[i].val) {
                v[j].cnt += b[i].cnt;
                found = true;
                break;
            }
        }
        if (!found) {
            v[pos++] = b[i];
        }
    }
    for (int i = 1; i < pos; ++i) {
        int p = i;
        while (p > 0 && v[p - 1].cnt < v[p].cnt) {
            swap(v[p - 1], v[p]);
            p--;
        }
    }
    for (int i = pos - 1; i >= 4; --i) {
    int p = v[i].cnt;
    for (int j = i; j > i - 5; --j)
         v[j].cnt -= p;
}
    for (int i = 0; i < KV; ++i) {
        to[i] = v[i];
    }
}

void build(int node, int left, int right) {
    if (left == right) {
        aint[node][0] = {a[left], 1};
        for (int i = 1; i < KV; ++i) {
            aint[node][i] = {-i, 0};
        }
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        merge(aint[2 * node + 1], aint[2 * node + 2], aint[node]);
    }
}

void query(int node, int left, int right, int lq, int rq, Freq* ans) {
    if (lq <= left && right <= rq) {
        merge(ans, aint[node], ans);
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) {
            query(2 * node + 1, left, mid, lq, rq, ans);
        }
        if (rq > mid) {
            query(2 * node + 2, mid + 1, right, lq, rq, ans);
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        valuesPos[a[i]].push_back(i);
    }
    build(0, 0, n - 1);

    Freq ans[KV];
    vector<int> fans(q, n + 1);
    vector<int> left(q), right(q), ks(q);
    for (int _q = 0; _q < q; ++_q) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;

        for (int i = 0; i < KV; ++i) {
            ans[i] = {-i - 1, 0};
        }
        query(0, 0, n - 1, l, r, ans);
        for (int i = 0; i < KV; ++i) {
            if (ans[i].val > 0) {
                vQueries[ans[i].val].push_back(_q);
            }
        }
        left[_q] = l;
        right[_q] = r;
        ks[_q] = k;
    }
    FenwickTree t(n);
    for (int i = 1; i <= n; ++i) {
        for (int p: valuesPos[i]) {
            t.update(p, 1);
        }
        for (int _q: vQueries[i]) {
            int l = left[_q];
            int r = right[_q];
            int k = ks[_q];
            int fr = t.query(l, r);
            if ((int64_t) fr * k > r - l + 1 && i < fans[_q]) {
                fans[_q] = i;
            }
        }
        for (int p: valuesPos[i]) {
            t.update(p, -1);
        }
    }
    for (int v: fans) {
        if (v == n + 1) {
            v = -1;
        }
        cout << v << '\n';
    }
}