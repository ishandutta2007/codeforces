#include <bits/stdc++.h>

using namespace std;

template<typename T>
void sci(T &t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T &t, Ts &... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

const int N = 500031;

vector<int> g[N];
int sz[N];
int tin[N];
int timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    sz[v] = 1;
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v);
            sz[v] += sz[i];
        }
    }
}

struct SegmentTree {
    int *a;
    int *st;

    SegmentTree(int n) {
        a = new int[4 * n];
        st = new int[4 * n];
        fill(a, a + 4 * n, 0);
        fill(st, st + 4 * n, -1);
    }

    void push(int i, int l, int r) {
        if (st[i] == -1) {
            return;
        }
        a[i] = st[i];
        if (l + 1 != r) {
            st[i * 2 + 1] = st[i];
            st[i * 2 + 2] = st[i];
        }
        st[i] = -1;
    }

    void set(int i, int l, int r, int ql, int qr, int qx) {
        push(i, l, r);
        if (r <= ql || qr <= l) {
            return;
        }
        if (ql <= l && r <= qr) {
            st[i] = qx;
            push(i, l, r);
            return;
        }

        int m = (l + r) >> 1;
        set(i * 2 + 1, l, m, ql, qr, qx);
        set(i * 2 + 2, m, r, ql, qr, qx);
        a[i] = max(a[i * 2 + 1], a[i * 2 + 2]);
    }

    int get(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (r <= ql || qr <= l) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return a[i];
        }

        int m = (l + r) >> 1;
        return max(get(i * 2 + 1, l, m, ql, qr), get(i * 2 + 2, m, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    scid(n);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs(0, -1);
    
    SegmentTree stFull(n);
    SegmentTree stEmpty(n);
    
    scid(q);
    for (int t = 1; t <= q; t++) {
        scid(x, y);
        --y;
        if (x == 1) {
            stFull.set(0, 0, n, tin[y], tin[y] + sz[y], t);
        } else if (x == 2) {
            stEmpty.set(0, 0, n, tin[y], tin[y] + 1, t);
        } else {
            int fullTime = stFull.get(0, 0, n, tin[y], tin[y] + 1);
            int emptyTime = stEmpty.get(0, 0, n, tin[y], tin[y] + sz[y]);
            if (fullTime > emptyTime) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}