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
    lint* a;
    lint* add;

    SegmentTree(int n) {
        a = new lint[4 * n];
        add = new lint[4 * n];
        memset(a, 0, sizeof(lint) * 4 * n);
        memset(add, 0, sizeof(lint) * 4 * n);
    }

    void push(int i, int l, int r) {
        a[i] += add[i];
        if (l + 1 != r) {
            add[i * 2 + 1] += add[i];
            add[i * 2 + 2] += add[i];
        }
        add[i] = 0;
    }

    void upd(int i, int l, int r, int ql, int qr, int qx) {
        push(i, l, r);
        if (r <= ql || qr <= l) {
            return;
        }
        if (ql <= l && r <= qr) {
            add[i] += qx;
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        upd(i * 2 + 1, l, m, ql, qr, qx);
        upd(i * 2 + 2, m, r, ql, qr, qx);
        a[i] = min(a[i * 2 + 1], a[i * 2 + 2]);
    }

    lint rmq(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (r <= ql || qr <= l) {
            return 1e18;
        }

        if (ql <= l && r <= qr) {
            return a[i];
        }

        int m = (l + r) >> 1;
        return min(rmq(i * 2 + 1, l, m, ql, qr), rmq(i * 2 + 2, m, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        st.upd(0, 0, n, i, i + 1, x);
    }

    scid(m);
    string s;
    getline(cin, s);
    while (m-- > 0) {
        getline(cin, s);
//        cout << s << endl;
        stringstream ss(s);
        int l1, r1;
        ss >> l1 >> r1;
        int l2, r2;
        bool ff = false;
        if (l1 <= r1) {
            l2 = l1;
            r2 = r1;
        } else {
            r2 = r1;
            l2 = 0;
            r1 = n - 1;
            ff = true;
        }

        int v;
        if (ss >> v) {
            st.upd(0, 0, n, l1, r1 + 1, v);
            if (ff) {
                st.upd(0, 0, n, l2, r2 + 1, v);
            }
        } else {
            cout << min(st.rmq(0, 0, n, l1, r1 + 1), st.rmq(0, 0, n, l2, r2 + 1)) << "\n";
        }
    }



    return 0;
}