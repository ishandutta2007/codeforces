#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int INF = 0x3f3f3f3f;

class SegmentTree {
public:
    SegmentTree(int _n):
        treeMin(4 * _n + 5, INF), treeMax(4 * _n + 5, -INF), n(_n) {}

    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }

    pair<int, int> query(int lq, int rq) {
        return query(0, 0, n - 1, lq, rq);
    }

private:
    vector<int> treeMin, treeMax;
    int n;

    void update(int node, int left, int right, int pos, int val) {
        if (left == right) {
            treeMin[node] = treeMax[node] = val;
        } else {
            int mid = (left + right) / 2;
            if (pos <= mid) {
                update(2 * node + 1, left, mid, pos, val);
            } else {
                update(2 * node + 2, mid + 1, right, pos, val);
            }
            treeMin[node] = min(treeMin[2 * node + 1], treeMin[2 * node + 2]);
            treeMax[node] = max(treeMax[2 * node + 1], treeMax[2 * node + 2]);
        }
    }

    pair<int, int> query(int node, int left, int right, int lq, int rq) {
        if (lq <= left && right <= rq) {
            return make_pair(treeMin[node], treeMax[node]);
        } else {
            int mid = (left + right) / 2;
            pair<int, int> ret = make_pair(INF, -INF);
            if (lq <= mid) {
                ret = query(2 * node + 1, left, mid, lq, rq);
            }
            if (rq > mid) {
                pair<int, int> v = query(2 * node + 2, mid + 1, right, lq, rq);
                ret.first = min(ret.first, v.first);
                ret.second = max(ret.second, v.second);
            }
            return ret;
        }
    }
};

struct Segment {
    int left, right, cnt;
    Segment() {}
    Segment(int _left, int _right, int _cnt = 0):
        left(_left), right(_right), cnt(_cnt) {}
    bool operator<(const Segment& o) const {
        return left < o.left || (left == o.left && right < o.right);
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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> all(k, vector<int>(n));
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
            all[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < k; ++i) {
        sort(all[i].begin(), all[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            a[i][j] = lower_bound(all[j].begin(), all[j].end(), a[i][j]) - all[j].begin();
        }
    }
    set<Segment> segs;
    vector<SegmentTree> trees;
    for (int i = 0; i < k; ++i) {
        trees.push_back(SegmentTree(n));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            trees[j].update(a[i][j], a[i][0]);
        }
        int left = a[i][0], right = a[i][0];
        for (int j = 0; j < k; ++j) {
            right = max(right, trees[j].query(0, a[i][j]).second);
            left = min(left, trees[j].query(a[i][j], n - 1).first);
        }
        Segment cseg = Segment(a[i][0], a[i][0], 1);
        while (true) {
            auto it = segs.lower_bound(cseg);
            if (it == segs.end()) {
                break;
            }
            if (it->left <= right) {
                cseg.right = it->right;
                cseg.cnt += it->cnt;
                segs.erase(it);
            } else {
                break;
            }
        }
        while (true) {
            auto it = segs.lower_bound(cseg);
            if (it == segs.begin()) {
                break;
            }
            --it;
            if (it->right >= left) {
                cseg.left = it->left;
                cseg.right = max(cseg.right, it->right);
                cseg.cnt += it->cnt;
                segs.erase(it);
            } else {
                break;
            }
        }
        segs.insert(cseg);
        auto it = segs.end();
        --it;
        cout << it->cnt << '\n';
    }

}