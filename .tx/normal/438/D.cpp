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
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

struct SegmentTree {
    lint* a;
    lint* mx;
    
    SegmentTree(int n) {
        a = new lint[4 * n];
        fill(a, a + 4 * n, 0);
        mx = new lint[4 * n];
        fill(mx, mx + 4 * n, 0);
    }
    
    lint get(int i, int l, int r, int ql, int qr) {
        if (r <= ql || qr <= l) {
            return 0;
        }
        
        if (ql <= l && r <= qr) {
            return a[i];
        }
        
        int m = (l + r) >> 1;
        return get(i * 2 + 1, l, m, ql, qr) + get(i * 2 + 2, m, r, ql, qr);
    }
    
    void mod(int i, int l, int r, int ql, int qr, int qx) {
        if (r <= ql || qr <= l) {
            return;
        }
        if (mx[i] < qx) {
            return;
        }
        if (l + 1 == r) {
            a[i] %= qx;
            mx[i] = a[i];
            return;
        }
        int m = (l + r) >> 1;
        mod(i * 2 + 1, l, m, ql, qr, qx);
        mod(i * 2 + 2, m, r, ql, qr, qx);
        mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
        a[i] = a[i * 2 + 1] + a[i * 2 + 2];
    }
    
    void set(int i, int l, int r, int qi, int qx) {
        if (l + 1 == r) {
            a[i] = qx;
            mx[i] = qx;
            return;
        }
        int m = (l + r) >> 1;
        if (qi < m) {
            set(i * 2 + 1, l, m, qi, qx);
        } else {
            set(i * 2 + 2, m, r, qi, qx);
        }
        mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
        a[i] = a[i * 2 + 1] + a[i * 2 + 2];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    scid(n, m);
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        st.set(0, 0, n, i, x);
    }
    
    while (m-- > 0) {
        scid(t);
        if (t == 1) {
            scid(l, r);
            --l; --r;
            cout << st.get(0, 0, n, l, r + 1) << "\n";
        } else if (t == 2) {
            scid(l, r, x);
            --l; --r;
            st.mod(0, 0, n, l, r + 1, x);
        } else {
            scid(k, x);
            --k;
            st.set(0, 0, n, k, x);
        }
    }
    
    

    return 0;
}