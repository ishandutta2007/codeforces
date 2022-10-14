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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 3e5 + 101, logN = 18;

template <typename T>
struct Seg {
    // range add value, range query sum
    // 0-indexed, [l, r)
    int l, r, m;
    T val;
    Seg *ch[2];
    Seg () = default;
    Seg (int _l, int _r, vector <T> &a) : l(_l), r(_r), m(l + r >> 1), val(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            val = a[l];
        }
    }
    void pull() {
        val = min(ch[0]->val, ch[1]->val);
    }
    void set(int p, int v) {
        if (r - l == 1)
            val = v;
        else
            ch[p >= m]->set(p, v), pull();
    }
    T query(int a, int b) {
        if (a <= l && r <= b)
            return val;
        T ans = 1 << 30;
        if (a < m)
            ans = min(ans, ch[0]->query(a, b));
        if (m < b)
            ans = min(ans, ch[1]->query(a, b));
        return ans;
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Seg <int> root(0, n, a);
        set <int> imp;
        for (int i = 1, mn = a[0]; i < n; ++i) {
            if (mn > a[i])
                imp.insert(i);
            mn = min(mn, a[i]);
        }
        while (q--) {
            int p, v; cin >> p >> v, --p;
            a[p] -= v;
            if (p && root.query(0, p) > a[p])
                imp.insert(p);
            root.set(p, a[p]);
            while (true) {
                auto it = imp.upper_bound(p);
                if (it == imp.end())
                    break;
                if (root.query(0, *it) <= a[*it])
                    imp.erase(it);
                else
                    break;
            }
            cout << imp.size() + 1 << ' ';
        }
        cout << '\n';
    }
}