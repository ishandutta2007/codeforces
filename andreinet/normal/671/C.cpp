#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 200005;
const int VMAX = 200000;

int64_t fans[NMAX];
vector<int> divs[NMAX];
int max1[NMAX], max2[NMAX], min1[NMAX], min2[NMAX];

class SegmentTree {
public:
    SegmentTree(int _n):
        sum(vector<int64_t>(4 * _n, 0)),
        vmax(vector<int>(4 * _n, 0)),
        vmin(vector<int>(4 * _n, 0)),
        lazy(vector<bool>(4 * _n, false)),
        n(_n) {}

    void update(int left, int right, int value) {
        if (left <= right) {
            update(0, 0, n - 1, left, right, value);
        }
    }
    int64_t query() const {
        return sum[0];
    }
private:
    vector<int64_t> sum;
    vector<int> vmax, vmin;
    vector<bool> lazy;
    int n;

    void split(int node, int left, int right) {
        if (lazy[node]) {
            lazy[node] = false;
            if (left == right) return;
            int mid = (left + right) / 2;
            vmax[2 * node + 1] = vmax[node];
            vmax[2 * node + 2] = vmax[node];
            vmin[2 * node + 1] = vmin[node];
            vmin[2 * node + 2] = vmin[node];
            sum[2 * node + 1] = (int64_t) vmax[node] * (mid - left + 1);
            sum[2 * node + 2] = (int64_t) vmax[node] * (right - mid);
            lazy[2 * node + 1] = true;
            lazy[2 * node + 2] = true;
        }
    }

    void update(int node, int left, int right, int lq, int rq, int value) {
        split(node, left, right);
        if (vmin[node] >= value) {
            return;
        }
        if (lq <= left && right <= rq && vmax[node] <= value) {
            vmin[node] = vmax[node] = value;
            sum[node] = (int64_t) value * (right - left + 1);
            lazy[node] = true;
        } else {
            int mid = (left + right) / 2;
            if (lq <= mid) {
                update(2 * node + 1, left, mid, lq, rq, value);
            }
            if (rq > mid) {
                update(2 * node + 2, mid + 1, right, lq, rq, value);
            }
            split(2 * node + 1, left, mid);
            split(2 * node + 2, mid + 1, right);
            vmax[node] = max(vmax[2 * node + 1], vmax[2 * node + 2]);
            vmin[node] = min(vmin[2 * node + 1], vmin[2 * node + 2]);
            sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
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

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    memset(max1, -1, sizeof max1);
    memset(max2, -1, sizeof max2);
    memset(min1, -1, sizeof min1);
    memset(min2, -1, sizeof min2);
    for (int i = 1; i <= VMAX; ++i) {
        for (int j = i; j <= VMAX; j += i) {
            divs[j].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int p: divs[A[i]]) {
            max2[p] = max1[p];
            max1[p] = i;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int p: divs[A[i]]) {
            min2[p] = min1[p];
            min1[p] = i;
        }
    }

    SegmentTree t(n);
    for (int i = 0; i < n; ++i) {
        t.update(i, i, i);
    }
    for (int i = VMAX; i >= 0; --i) {
        fans[i] = (int64_t) n * n - t.query();
        if (min2[i] != -1) {
            t.update(0, min1[i], max2[i]);
            t.update(min1[i] + 1, min2[i], max1[i]);
            t.update(min2[i] + 1, n - 1, n);
        }
    }
    int64_t ans = 0;
    for (int i = VMAX; i > 0; --i) {
        ans += i * (fans[i] - fans[i - 1]);
    }
    cout << ans << '\n';
}