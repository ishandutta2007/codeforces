#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int64_t LINF = 1LL << 60;

vector<int64_t> pw42;

class SegmentTree {
public:
    SegmentTree(const vector<int>& values):
        vals(vector<int64_t>(SZ(values))),
        nextv(vector<int64_t>(4 * SZ(values))),
        lazyAdd(vector<int64_t>(4 * SZ(values))),
        lazySet(vector<int64_t>(4 * SZ(values))),
        ind(vector<int>(SZ(values))),
        n(SZ(values)) {
            build(0, 0, n - 1, values);
        }


    void set(int left, int right, int value) {
        if (left > 0 && getValue(0, 0, n - 1, left - 1) == LINF) {
            int64_t v = getFirst(0, 0, n - 1, left - 1);
            setPosition(0, 0, n - 1, left - 1, v);
        }
        if (left <= right - 1) {
            setSegment(0, 0, n - 1, left, right - 1);
        }
        setPosition(0, 0, n - 1, right, value);
    }
    
    void add(int left, int right, int value) {
        if (left > 0 && getValue(0, 0, n - 1, left - 1) == LINF) {
            int64_t v = getFirst(0, 0, n - 1, left - 1);
            setPosition(0, 0, n - 1, left - 1, v);
        }
        if (getValue(0, 0, n - 1, right) == LINF) {
            int64_t v = getFirst(0, 0, n - 1, right);
            setPosition(0, 0, n - 1, right, v);
        }
        addSegment(0, 0, n - 1, left, right, value);
        repair(0, 0, n - 1);
        while (nextv[0] <= 0) {
            assert(nextv[0] == 0);
            addSegment(0, 0, n - 1, left, right, value);
            repair(0, 0, n - 1);
        }
    }

    int64_t operator[](int pos) {
        return getFirst(0, 0, n - 1, pos);
    }
private:
    vector<int64_t> vals, nextv, lazyAdd, lazySet;
    vector<int> ind;
    int n;

    void build(int node, int left, int right, const vector<int>& values) {
        lazyAdd[node] = 0;
        lazySet[node] = -1;
        if (left == right) {
            ind[left] = 0;
            while (values[left] > pw42[ind[left]]) {
                ind[left]++;
            }
            nextv[node] = pw42[ind[left]] - values[left];
            vals[left] = values[left];
        } else {
            int mid = (left + right) / 2;
            build(2 * node + 1, left, mid, values);
            build(2 * node + 2, mid + 1, right, values);
            nextv[node] = min(nextv[2 * node + 1], nextv[2 * node + 2]);
        }
    }
    
    void split(int node, int left, int right) {
        if (lazySet[node] != -1) {
            nextv[node] = lazySet[node];
            if (left < right) {
                lazySet[2 * node + 1] = lazySet[node];
                lazyAdd[2 * node + 1] = 0;
                lazySet[2 * node + 2] = lazySet[node];
                lazyAdd[2 * node + 2] = 0;
            } else {
                ind[left] = 50;
                vals[left] = lazySet[node];
            }
            lazySet[node] = -1;
        }
        if (lazyAdd[node] != 0) {
            if (nextv[node] != LINF) {
                nextv[node] -= lazyAdd[node];
            }
            if (left < right) {
                lazyAdd[2 * node + 1] += lazyAdd[node];
                lazyAdd[2 * node + 2] += lazyAdd[node];
            } else {
                if (vals[left] != LINF) {
                    vals[left] += lazyAdd[node];
                }
            }
            lazyAdd[node] = 0;
        }
    }

    void setSegment(int node, int left, int right, int lq, int rq) {
        split(node, left, right);
        if (lq <= left && right <= rq) {
            lazySet[node] = LINF;
        } else {
            int mid = (left + right) / 2;
            if (lq <= mid) {
                setSegment(2 * node + 1, left, mid, lq, rq);
            }
            if (rq > mid) {
                setSegment(2 * node + 2, mid + 1, right, lq, rq);
            }
            split(2 * node + 1, left, mid);
            split(2 * node + 2, mid + 1, right);
            nextv[node] = min(nextv[2 * node + 1], nextv[2 * node + 2]);
        }
    }

    void setPosition(int node, int left, int right, int pos, int64_t value) {
        split(node, left, right);
        if (left == right) {
            ind[left] = 0;
            while (value > pw42[ind[left]]) {
                ind[left]++;
            }
            nextv[node] = pw42[ind[left]] - value;
            vals[left] = value;
        } else {
            int mid = (left + right) / 2;
            if (pos <= mid) {
                setPosition(2 * node + 1, left, mid, pos, value);
            } else {
                setPosition(2 * node + 2, mid + 1, right, pos, value);
            }
            split(2 * node + 1, left, mid);
            split(2 * node + 2, mid + 1, right);
            nextv[node] = min(nextv[2 * node + 1], nextv[2 * node + 2]);
        }
    }

    void repair(int node, int left, int right) {
        split(node, left, right);
        if (nextv[node] >= 0) return;

        if (left == right) {
            while (vals[left] > pw42[ind[left]]) {
                ind[left]++;
            }
            nextv[node] = pw42[ind[left]] - vals[left];
        } else {
            int mid = (left + right) / 2;
            repair(2 * node + 1, left, mid);
            repair(2 * node + 2, mid + 1, right);
            nextv[node] = min(nextv[2 * node + 1], nextv[2 * node + 2]);
        }
    }

    void addSegment(int node, int left, int right, int lq, int rq, int value) {
        split(node, left, right);
        if (lq <= left && right <= rq) {
            lazyAdd[node] += value;
        } else {
            int mid = (left + right) / 2;
            if (lq <= mid) {
                addSegment(2 * node + 1, left, mid, lq, rq, value);
            }
            if (rq > mid) {
                addSegment(2 * node + 2, mid + 1, right, lq, rq, value);
            }
            split(2 * node + 1, left, mid);
            split(2 * node + 2, mid + 1, right);
            nextv[node] = min(nextv[2 * node + 1], nextv[2 * node + 2]);
        }
    }

    int64_t getFirst(int node, int left, int right, int lq) {
         split(node, left, right);
         if (nextv[node] == LINF) {
            return -1;
         }
         if (left == right) {
            return vals[left];
         } else {
            int mid = (left + right) / 2;
            int64_t ret = -1;
            if (lq <= mid) {
                ret = getFirst(2 * node + 1, left, mid, lq);
            }
            if (ret == -1) {
                ret = getFirst(2 * node + 2, mid + 1, right, lq);
            }
            return ret;
        }
    }
    
    int64_t getValue(int node, int left, int right, int pos) {
        split(node, left, right);
        if (left == right) {
            return vals[left];
        } else {
            int mid = (left + right) / 2;
            if (pos <= mid) {
                return getValue(2 * node + 1, left, mid, pos);
            } else {
                return getValue(2 * node + 2, mid + 1, right, pos);
            }
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

    pw42 = {42};
    for (int i = 1; i < 11; ++i) {
        pw42.push_back(pw42.back() * 42);
    }

    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    SegmentTree t(values);
    while (q-- > 0) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos;
            cin >> pos;
            cout << t[pos - 1] << '\n';
        } else if (type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            t.set(a - 1, b - 1, x);
        } else if (type == 3) {
            int a, b, x;
            cin >> a >> b >> x;
            t.add(a - 1, b - 1, x);
        }
    }
}