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

    SegmentTree(int n) {
        a = new int[4 * n];
        st = new int[4 * n];
        fill(st, st + 4 * n, -1);
        build(0, 0, n);
    }

    void build(int i, int l, int r) {
        if (l + 1 == r) {
            a[i] = 1;
        } else {
            int m = (l + r) >> 1;
            build(i * 2 + 1, l, m);
            build(i * 2 + 2, m, r);
            a[i] = a[i * 2 + 1] + a[i * 2 + 2];
        }
    }

    void push(int i, int l, int r) {
        if (st[i] == -1) {
            return;
        }
        a[i] = st[i] * (r - l);
        if (l + 1 != r) {
            st[i * 2 + 1] = st[i];
            st[i * 2 + 2] = st[i];
        }
        st[i] = -1;
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
};

vector<int> p[33];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(m);
    scids(s);
    int n = s.size();

    for (int i = 0; i < n; i++) {
        p[s[i] - 'a'].push_back(i);
    }

    SegmentTree st(n);
    if (m != 1) {
        st.set(0, 0, n, n - m + 1, n, 0);
    }
    string ans = "";

    for (int c = 0; c < 26; c++) {
        int rem = st.get(0, 0, n, 0, n);
        if (rem == 0) {
            break;
        }
        string nt = "";
        for (int ii = 0; ii < p[c].size(); ii++) {
            int i = p[c][ii];
            int cc = 0;
            if (ii + 1 < p[c].size()) {
                int d = p[c][ii + 1] - i;
                if (d < m) {
                    cc = st.get(0, 0, n, max(0, i - (m - d) + 1), i + 1);
                }
            }
            int c2 = st.get(0, 0, n, max(0, i - m + 1), i + 1);
            if (c2 == cc) {
                nt += (char) (c + 'a');
                continue;
            }
            ans += (char) (c + 'a');
            st.set(0, 0, n, max(0, i - m + 1), (i + 1), 0);
//            if (st.get(0, 0, n, max(0, i - m + 1), i + 1) == rem) {
//                ans += (char) (c + 'a');
//                cout << ans;
//                return 0;
//            }
        }
        rem = st.get(0, 0, n, 0, n);
        if (rem == 0) {
            break;
        }

        for (char z : nt) {
            ans += z;
        }

        for (int i : p[c]) {
            st.set(0, 0, n, max(0, i - m + 1), i + 1, 0);
//            ans += (char) (c + 'a');
        }
    }

    cout << ans;

    return 0;
}