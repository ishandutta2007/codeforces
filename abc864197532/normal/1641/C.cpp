#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200005, logN = 18, K = 1 << 8, G = 3;

struct Seg {
    int l, r, m, mx, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mx(-1), lz(-1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {mx = max(ch[0]->mx, ch[1]->mx);}
    void give(int v) {
        mx = lz = v;
    }
    void push() {
        if (lz == -1)
            return;
        ch[0]->give(lz), ch[1]->give(lz);
        lz = -1;
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b)
            give(v);
        else {
            push();
            if (a < m)
                ch[0]->add(a, b, v);
            if (m < b)
                ch[1]->add(a, b, v);
            pull();
        }
    }
    int query(int a, int b) {
        if (a <= l && r <= b)
            return mx;
        push();
        int ans = -1;
        if (a < m)
            ans = max(ans, ch[0]->query(a, b));
        if (m < b)
            ans = max(ans, ch[1]->query(a, b));
        return ans;
    }
};

struct OP {
    int t, l, r, x;
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <OP> op(q);
    for (int i = 0; i < q; ++i) {
        cin >> op[i].t;
        if (op[i].t)
            cin >> op[i].x, --op[i].x;
        else
            cin >> op[i].l >> op[i].r >> op[i].x, --op[i].l;
    }
    Seg root(0, n);
    vector <int> most(n, q + 1);
    for (int i = q - 1; ~i; --i) {
        if (!op[i].t && op[i].x == 0) {
            root.add(op[i].l, op[i].r, i);
        }
    }
    set <int> unvis;
    for (int i = 0; i < n; ++i) {
        if (root.query(i, i + 1) == -1)
            unvis.insert(i);
    }
    for (int i = 0; i < q; ++i) {
        if (!op[i].t && op[i].x == 1) {
            auto it = unvis.lower_bound(op[i].l);
            if (it == unvis.end())
                continue;
            int x = *it;
            it = unvis.upper_bound(x);
            if (it == unvis.end() || *it >= op[i].r) {
                // x is the only point
                most[x] = min(most[x], max(root.query(op[i].l, op[i].r), i));
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if (op[i].t) {
            int x = root.query(op[i].x, op[i].x + 1);
            if (x != -1) {
                cout << (x < i ? "NO\n" : "N/A\n");
            } else {
                cout << (most[op[i].x] < i ? "YES\n" : "N/A\n");
            }
        }
    }
}