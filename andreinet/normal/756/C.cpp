#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define SZ(x) ((int) (x).size())
using namespace std;

const int NMAX = 100005;

int perm[NMAX];

int tmin[4 * NMAX], tmax[4 * NMAX];
int lazy[4 * NMAX];

void split(int node, int left, int right) {
    if (lazy[node]) {
        tmin[node] += lazy[node];
        tmax[node] += lazy[node];
        if (left < right) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int lq, int rq, int val) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        lazy[node] += val;
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
        tmin[node] = min(tmin[2 * node + 1], tmin[2 * node + 2]);
        tmax[node] = max(tmax[2 * node + 1], tmax[2 * node + 2]);
    }
}

int query(int node, int left, int right) {
    split(node, left, right);
    if (tmin[node] > 1 || tmax[node] < 1) {
        return -1;
    } else if (left == right) {
        return left;
    } else {
        int mid = (left + right) / 2;
        int ret = query(2 * node + 2, mid + 1, right);
        if (ret == -1) {
            ret = query(2 * node + 1, left, mid);
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
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p, t;
        cin >> p >> t;
        p--;

        if (t == 0) {
            update(0, 0, n - 1, 0, p, -1);
        } else {
            cin >> perm[p];
            update(0, 0, n - 1, 0, p, 1);
        }

        int ans = query(0, 0, n - 1);
        if (ans != -1) ans = perm[ans];
        cout << ans << '\n';
    }
}