#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

class FenwickTree {
public:
    FenwickTree(int n):
        tree(vector<int64_t>(n + 1, 0)) {}

    void add(int pos, int64_t value) {
        for (++pos; pos < SZ(tree); pos += pos & -pos) {
            tree[pos] += value;
        }
    }

    int64_t get(int pos) {
        int64_t ret = 0;
        for (++pos; pos > 0; pos -= pos & -pos) {
            ret += tree[pos];
        }
        return ret;
    }

    int64_t get(int left, int right) {
        if (left > right) {
            return 0;
        }
        return get(right) - get(left - 1);
    }

    void reset() {
        fill(tree.begin(), tree.end(), 0);
    }
private:
    vector<int64_t> tree;
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

    vector<int> P(2 * n, -1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        P[x] = y;
        P[y] = x;
    }

    FenwickTree t(2 * n);
    vector<int> inside(2 * n, 0);
    for (int i = 0; i < n + n; ++i) {
        int right = i;
        int left = P[i];
        if (left > right) {
            continue;
        }
        inside[i] = t.get(left + 1, right - 1);
        t.add(left, 1);
    }

    vector<int> segsLeft(2 * n, 0);
    vector<int> touchLeft(2 * n, 0);
    for (int i = 0; i < n + n; ++i) {
        int right = i;
        int left = P[i];
        if (left < right) {
            touchLeft[i] = segsLeft[right - 1] - segsLeft[left];
            segsLeft[i] = 1;
        }
        if (i > 0) {
            segsLeft[i] += segsLeft[i - 1];
        }
    }
    vector<int> segsRight(2 * n, 0);
    vector<int> touchRight(2 * n, 0);
    for (int i = 2 * n - 1; i >= 0; --i) {
        int left = i;
        int right = P[i];
        if (left < right) {
            touchRight[right] = segsRight[left + 1] - segsRight[right];
            segsRight[i] = 1;
        }
        if (i < 2 * n - 1) {
            segsRight[i] += segsRight[i + 1];
        }
    }
    vector<int> touch(2 * n, 0);
    for (int i = 0; i < n + n; ++i) {
        touch[i] = touchLeft[i] + touchRight[i] - 2 * inside[i];
    }
    int64_t cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n + n; ++i) {
        if (P[i] < i) {
            cnt1 += (int64_t) touch[i] * (n - 1 - touch[i]);
            cnt2 += (int64_t) inside[i] * (n - 1 - touch[i] - inside[i]);
        }
    }
    int64_t ans = (int64_t) n * (n - 1) * (n - 2) / 6;
    ans -= cnt1 / 2;
    ans -= cnt2;
    cout << ans << '\n';
}