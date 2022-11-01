#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int NMAX = 300005, INF = 0x3f3f3f3f;

struct Node {
    int min1, cnt1;
    int min2, cnt2;
    int lazy;
};
Node aint[4 * NMAX];

void split(int node, int left, int right) {
    if (aint[node].lazy) {
        aint[node].min1 += aint[node].lazy;
        aint[node].min2 += aint[node].lazy;
        if (left < right) {
            aint[2 * node + 1].lazy += aint[node].lazy;
            aint[2 * node + 2].lazy += aint[node].lazy;
        }
        aint[node].lazy = 0;
    }
}

void updateNode(int node) {
    aint[node].min1 = min(aint[2 * node + 1].min1, aint[2 * node + 2].min1);
    aint[node].min2 = INF;
    aint[node].cnt1 = aint[node].cnt2 = 0;
    for (int i = 1; i <= 2; ++i) {
        if (aint[2 * node + i].min1 != aint[node].min1) {
            if (aint[2 * node + i].min1 < aint[node].min2) {
                aint[node].min2 = aint[2 * node + i].min1;
                aint[node].cnt2 = aint[2 * node + i].cnt1;
            } else if (aint[2 * node + i].min1 == aint[node].min2) {
                aint[node].cnt2 += aint[2 * node + i].cnt1;
            }
        } else {
            aint[node].cnt1 += aint[2 * node + i].cnt1;
        }
        if (aint[2 * node + i].min2 != aint[node].min1) {
            if (aint[2 * node + i].min2 < aint[node].min2) {
                aint[node].min2 = aint[2 * node + i].min2;
                aint[node].cnt2 = aint[2 * node + i].cnt2;
            } else if (aint[2 * node + i].min2 == aint[node].min2) {
                aint[node].cnt2 += aint[2 * node + i].cnt2;
            }
        } else {
            aint[node].cnt1 += aint[2 * node + i].cnt1;
        }
    }
}

void build(int node, int left, int right) {
    if (left == right) {
        aint[node].min1 = 0;
        aint[node].min2 = INF;
        aint[node].cnt1 = 1;
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        updateNode(node);
    }
}

void update(int node, int left, int right, int lq, int rq, int val) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        aint[node].lazy += val;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) {
            update(2 * node + 1, left, mid, lq, rq, val);
        }
        if (rq > mid) {
            update(2 * node + 2, mid + 1, right, lq, rq, val);
        }
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        updateNode(node);
    }
}

int query(int node, int left, int right, int lq, int rq) {
    if (lq <= left && right <= rq) {
        int ret = 0;
        if (aint[node].min1 <= 2) {
            ret += aint[node].cnt1;
        }
        if (aint[node].min2 <= 2) {
            ret += aint[node].cnt2;
        }
        return ret;
    } else {
        int mid = (left + right) / 2, ret = 0;
        if (lq <= mid) {
            ret += query(2 * node + 1, left, mid, lq, rq);
        }
        if (rq > mid) {
            ret += query(2 * node + 2, mid + 1, right, lq, rq);
        }
        return ret;
    }
}

int main()
{
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // LOCAL_RUN
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n), pos(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        A[x] = i;
        pos[i] = x;
    }
    build(0, 0, n - 1);

    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int v = A[i];
        int p1, p2;
        if (v - 1 < 0) {
            p1 = -1;
        } else {
            p1 = pos[v - 1];
        }
        if (v + 1 >= n) {
            p2 = -1;
        } else {
            p2 = pos[v + 1];
        }
        if (p1 >= i) {
            p1 = -1;
        }
        if (p2 >= i) {
            p2 = -1;
        }
        if (p1 > p2) {
            swap(p1, p2);
        }
        if (p1 >= 0) {
            update(0, 0, n - 1, 0, p1, -1);
        }
        if (p2 + 1 <= i) {
            update(0, 0, n - 1, p2 + 1, i, 1);
        }
        ans += query(0, 0, n - 1, 0, i);
    }
    ans -= n;
    cout << ans << '\n';
}