#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

struct SegmentTree {
    int* a;
    int* st;

    SegmentTree() {}

    SegmentTree(int n) {
        a = new int[4 * n];
        st = new int[4 * n];
        memset(a, 0, sizeof(int) * 4 * n);
        memset(st, -1, sizeof(int) * 4 * n);
    }

    void push(int i, int l, int r) {
        if (st[i] != -1) {
            a[i] = st[i] * (r - l);
            if (l + 1 != r) {
                st[i * 2 + 1] = st[i];
                st[i * 2 + 2] = st[i];
            }
            st[i] = -1;
        }
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
        a[i] = a[i * 2 + 1] + a[i * 2 + 2];
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
        return get(i * 2 + 1, l, m, ql, qr) + get(i * 2 + 2, m, r, ql, qr);
    }
};

SegmentTree sts[33];
int cnts[33];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, q);
    for (int i = 0; i < 26; i++) {
        sts[i] = SegmentTree(n);
    }
    scids(s);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        sts[c].set(0, 0, n, i, i + 1, 1);
    }

    while (q-- > 0) {
        scid(l, r, k);
        --l; --r;
        for (int i = 0; i < 26; i++) {
            cnts[i] = sts[i].get(0, 0, n, l, r + 1);
            sts[i].set(0, 0, n, l, r + 1, 0);
        }

        int cc = l;
        if (k == 1) {
            for (int i = 0; i < 26; i++) {
                sts[i].set(0, 0, n, cc, cc + cnts[i], 1);
                cc += cnts[i];
            }
        } else {
            for (int i = 25; i >= 0; i--) {
                sts[i].set(0, 0, n, cc, cc + cnts[i], 1);
                cc += cnts[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            int x = sts[j].get(0, 0, n, i, i + 1);
            if (x == 1) {
                cout << ((char) (j + 'a'));
            }
        }
    }


    return 0;
}