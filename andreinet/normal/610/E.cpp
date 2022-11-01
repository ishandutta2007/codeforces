#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 200005;

int n, k, lim;

char A[NMAX];
int aint[4 * NMAX][100];
bool lazy[4 * NMAX];

char alet[4 * NMAX];

void asplit(int node, int left, int right) {
    if (alet[node] == 0) return;
    if (left < right) {
        alet[2 * node + 1] = alet[node];
        alet[2 * node + 2] = alet[node];
        alet[node] = 0;
    }
}

int getCh(int node, int left, int right, int pos) {
    asplit(node, left, right);
    if (left == right) {
        return alet[node] == 0 ? A[left]: alet[node];
    } else {
        int mid = (left + right) / 2;
        if (pos <= mid) return getCh(2 * node + 1, left, mid, pos);
        else return getCh(2 * node + 2, mid + 1, right, pos);
    }
}

void updateCh(int node, int left, int right, int lq, int rq, char val) {
    asplit(node, left, right);
    if (lq <= left && right <= rq) {
        alet[node] = val;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) updateCh(2 * node + 1, left, mid, lq, rq, val);
        if (rq > mid) updateCh(2 * node + 2, mid + 1, right, lq, rq, val);
    }
}

void build(int node, int left, int right) {
    if (left == right) {
        assert('a' <= A[left - 1] && A[left - 1] <= 'z');
        assert('a' <= A[left] && A[left] <= 'z');

        memset(aint[node], 0, sizeof aint[node]);
        aint[node][(A[left - 1] - 'a') * k + (A[left] - 'a')] = 1;
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        for (int i = 0; i < lim; ++i) {
            aint[node][i] = aint[2 * node + 1][i] + aint[2 * node + 2][i];
        }
    }
}

void split(int node, int left, int right) {
    if (!lazy[node]) return;
    memset(aint[node], 0, sizeof aint[node]);
    if (left < right) {
        lazy[2 * node + 1] = true;
        lazy[2 * node + 2] = true;
    }
    lazy[node] = false;
}

void update(int node, int left, int right, int lq, int rq) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        lazy[node] = true;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) update(2 * node + 1, left, mid, lq, rq);
        if (rq > mid) update(2 * node + 2, mid + 1, right, lq, rq);
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        for (int i = 0; i < lim; ++i) {
            aint[node][i] = aint[2 * node + 1][i] + aint[2 * node + 2][i];
        }
    }
}

void updatePos(int node, int left, int right, int pos, char pc1, char pc2) {
    split(node, left, right);
    if (left == right) {
        assert('a' <= pc1 && pc1 <= 'z');
        assert('a' <= pc2 && pc2 <= 'z');

        memset(aint[node], 0, sizeof aint[node]);
        aint[node][(pc1 - 'a') * k + (pc2 - 'a')] = 1;
    } else {
        int mid = (left + right) / 2;
        if (pos <= mid) updatePos(2 * node + 1, left, mid, pos, pc1, pc2);
        else updatePos(2 * node + 2, mid + 1, right, pos, pc1, pc2);
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        for (int i = 0; i < lim; ++i) {
            aint[node][i] = aint[2 * node + 1][i] + aint[2 * node + 2][i];
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

    int q;
    cin >> n >> q >> k;

    lim = k * k;

    cin >> A + 1;
    if (n >= 2 && k >= 2) {
        build(0, 2, n);
    }

    for (int qt = 1; qt <= q; ++qt) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            char c;
            cin >> l >> r >> c;

            updateCh(0, 1, n, l, r, c);
            if (n >= 2 && k >= 2) {
                if (r > 1)
                    update(0, 2, n, max(l, 2), r);
                if (l > 1) {
                    char pc1 = getCh(0, 1, n, l - 1);
                    char pc2 = c;
                    updatePos(0, 2, n, l, pc1, pc2);
                }
                if (r < n) {
                    char pc1 = c;
                    char pc2 = getCh(0, 1, n, r + 1);
                    updatePos(0, 2, n, r + 1, pc1, pc2);
                }
            }
        } else {
            string p;
            cin >> p;
            int ans = n;
            if (n >= 2 && k >= 2) {
                split(0, 2, n);
            }

            for (int i = 0; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    ans -= aint[0][(p[i] - 'a') * k + (p[j] - 'a')];
                }
            }

            cout << ans << '\n';
        }
        //cerr << qt << endl;
    }
}