#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

class SegmentTree {
public:
    SegmentTree(int _n):
        tree(4 * _n + 5, 0),
        lazy(4 * _n + 5, 0),
        n(_n) {}
    void add(int left, int right, int value) {
        add(0, 0, n - 1, left, right, value);
    }
    int64_t query(int left, int right) {
        if (left > right) {
            return -15;
        }
        return query(0, 0, n - 1, left, right);
    }
private:
    vector<int64_t> tree, lazy;
    int n;

    void split(int node, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (left < right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void add(int node, int left, int right, int lq, int rq, int value) {
        split(node, left, right);
        if (lq <= left && right <= rq) {
            lazy[node] += value;
        } else {
            int mid = (left + right) / 2;
            if (lq <= mid) {
                add(2 * node + 1, left, mid, lq, rq, value);
            }
            if (rq > mid) {
                add(2 * node + 2, mid + 1, right, lq, rq, value);
            }
            split(2 * node + 1, left, mid);
            split(2 * node + 2, mid + 1, right);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    int64_t query(int node, int left, int right, int lq, int rq) {
        split(node, left, right);
        if (lq <= left && right <= rq) {
            return tree[node];
        } else {
            int mid = (left + right) / 2;
            int64_t ret = 0;
            if (lq <= mid) {
                ret = query(2 * node + 1, left, mid, lq, rq);
            }
            if (rq > mid) {
                ret = max(ret, query(2 * node + 2, mid + 1, right, lq, rq));
            }
            return ret;
        }
    }
};

struct Query {
    char c;
    int t, d;
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    vector<int> knights;
    vector<Query> qs(q);
    for (Query& p: qs) {
        cin >> p.c >> p.t;
        if (p.c == '+') {
            cin >> p.d;
            knights.push_back(p.t);
        }
    }
    vector<int> times = knights;
    sort(times.begin(), times.end());
    SegmentTree t(SZ(times)), sum(SZ(times));
    for (Query& p: qs) {
        if (p.c == '-') {
            int ti = qs[p.t - 1].t;
            int pos = lower_bound(times.begin(), times.end(), ti) - times.begin();
            t.add(pos, pos, -ti);
            t.add(0, pos, -qs[p.t - 1].d);
            sum.add(0, pos, -qs[p.t - 1].d);
        } else if (p.c == '+') {
            int pos = lower_bound(times.begin(), times.end(), p.t) - times.begin();
            t.add(pos, pos, p.t);
            t.add(0, pos, p.d);
            sum.add(0, pos, p.d);
        } else {
            int pos = upper_bound(times.begin(), times.end(), p.t) - times.begin() - 1;
            int64_t value = t.query(0, pos) - max((int64_t) 0, sum.query(pos + 1, SZ(times) - 1));
            cout << max((int64_t) 0, value - p.t) << '\n';
        }
    }
}