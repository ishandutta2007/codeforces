#include <bits/stdc++.h>
using namespace std;

const int N = 100005, mod = 1e9 + 7;

int pw[9];

bool chk(int a, int p) {
    return (a / pw[p]) % 10 > 0;
}

struct val {
    int mn[2][9], cnt[9];
    val () {
        for (int i = 0; i < 9; ++i) mn[0][i] = mn[1][i] = 1e9, cnt[i] = 0;
    }
    val operator + (const val& other) {
        val ans;
        for (int k = 0; k < 9; ++k) {
            ans.cnt[k] = cnt[k] + other.cnt[k];
            for (int i = 0; i < 2; ++i) {
                if (ans.mn[0][k] >= mn[i][k]) {
                    ans.mn[1][k] = ans.mn[0][k];
                    ans.mn[0][k] = mn[i][k];
                } else if (ans.mn[1][k] >= mn[i][k]) {
                    ans.mn[1][k] = mn[i][k];
                }
                if (ans.mn[0][k] >= other.mn[i][k]) {
                    ans.mn[1][k] = ans.mn[0][k];
                    ans.mn[0][k] = other.mn[i][k];
                } else if (ans.mn[1][k] >= other.mn[i][k]) {
                    ans.mn[1][k] = other.mn[i][k];
                }
            }
        }
        return ans;
    }
    void operator = (const val& other) {
        for (int i = 0; i < 9; ++i) {
            mn[0][i] = other.mn[0][i];
            mn[1][i] = other.mn[1][i];
            cnt[i] = other.cnt[i];
        }
    }
};

struct Seg {
    int l, r, m;
    val sum;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1) {
        sum = val();
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            for (int k = 0; k < 9; ++k) {
                if (chk(a[l], k)) {
                    sum.mn[0][k] = a[l];
                    sum.cnt[k] = 1;
                }
            }
        }
    }
    void pull() {sum = (ch[0]->sum + ch[1]->sum);}
    void set(int p, int v) {
        if (r - l == 1) {
            for (int k = 0; k < 9; ++k) {
                if (chk(v, k)) {
                    sum.mn[0][k] = v;
                    sum.cnt[k] = 1;
                } else {
                    sum.mn[0][k] = 1e9;
                    sum.cnt[k] = 0;
                }
            }
        } else {
            ch[p >= m]->set(p, v);
            pull();
        }
    }
    val query(int a, int b) {
        if (a <= l && r <= b) return sum;
        val ans = val();
        if (a < m) {
            val A = ch[0]->query(a, b);
            ans = ans + A;
        }
        if (m < b) {
            val A = ch[1]->query(a, b);
            ans = ans + A;
        }
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i < 9; ++i) pw[i] = pw[i - 1] * 10;
    int n, q, t, l, r;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Seg root(0, n, a);
    while (q--) {
        cin >> t >> l >> r, l--;
        if (t == 1) {
            root.set(l, r);
        } else {
            int ans = 2e9;
            val re = root.query(l, r);
            for (int k = 0; k < 9; ++k) {
                if (re.mn[1][k] < int(1e9)) ans = min(ans, re.mn[0][k] + re.mn[1][k]);
            }
            if (ans == int(2e9)) ans = -1;
            cout << ans << endl;
        }
    }
}