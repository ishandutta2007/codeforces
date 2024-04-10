#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

class SegmentTree {
public:
    SegmentTree(int _n):
        tree(vector<int>(4 * _n + 5, -1)), n(_n) {
        }

    void set(int pos, int value) {
        update(0, 0, n - 1, pos, value);
    }
    int max(int left, int right) {
        if (left > right) {
            return -1;
        }
        return query(0, 0, n - 1, left, right);
    }
private:
    vector<int> tree;
    int n;

    void update(int node, int left, int right, int pos, int value) {
        if (left == right) {
            tree[node] = value;
        } else {
            int mid = (left + right) / 2;
            if (pos <= mid) {
                update(2 * node + 1, left, mid, pos, value);
            } else {
                update(2 * node + 2, mid + 1, right, pos, value);
            }
            tree[node] = ::max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    int query(int node, int left, int right, int lq, int rq) {
        if (lq <= left && right <= rq) {
            return tree[node];
        } else {
            int mid = (left + right) / 2, ret = -1;
            if (lq <= mid) {
                ret = query(2 * node + 1, left, mid, lq, rq);
            }
            if (rq > mid) {
                ret = ::max(ret, query(2 * node + 2, mid + 1, right, lq, rq));
            }
            return ret;
        }
    }
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> allValues;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        allValues.push_back(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        allValues.push_back(b[i]);
    }
    sort(allValues.begin(), allValues.end());
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
    
    int k = SZ(allValues);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(allValues.begin(), allValues.end(), a[i])
            - allValues.begin();
        b[i] = lower_bound(allValues.begin(), allValues.end(), b[i])
            - allValues.begin();
    }

    vector<int> stk;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && a[stk.back()] < a[i]) {
            stk.pop_back();
        }
        if (stk.empty()) {
            left[i] = 0;
        } else {
            left[i] = stk.back() + 1;
        }
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }
        if (stk.empty()) {
            right[i] = n - 1;
        } else {
            right[i] = stk.back() - 1;
        }
        stk.push_back(i);
    }

    SegmentTree t1(k);
    vector<int> lPosEq(n), lPosSmaller(n);
    for (int i = 0; i < n; ++i) {
        t1.set(b[i], i);
        lPosEq[i] = t1.max(a[i], a[i]);
        lPosSmaller[i] = t1.max(0, a[i] - 1);
    }
    SegmentTree t2(k);
    vector<int> rPosEq(n), rPosSmaller(n);
    for (int i = n - 1; i >= 0; --i) {
        t2.set(b[i], n - i - 1);
        rPosEq[i] = n - t2.max(a[i], a[i]) - 1;
        rPosSmaller[i] = n - t2.max(0, a[i] - 1) - 1;
    }

    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = left[i], r = right[i];

        l = max(l, lPosSmaller[i] + 1);
        r = min(r, rPosSmaller[i] - 1);
        if (l <= lPosEq[i]) {
            ans += (int64_t) (lPosEq[i] - l + 1) * (r - i + 1);
        }
        if (rPosEq[i] <= r) {
            ans += (int64_t) (i - l + 1) * (r - rPosEq[i] + 1);
        }
        if (l <= lPosEq[i] && rPosEq[i] <= r) {
            ans -= (int64_t) (lPosEq[i] - l + 1) * (r - rPosEq[i] + 1);
        }
    }
    cout << ans << '\n';
}