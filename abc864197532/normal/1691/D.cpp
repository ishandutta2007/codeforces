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
const int mod = 1e9 + 7, N = 200005, logN = 20, K = 48763;

template <typename T>
struct Seg {
    // range add value, range query sum
    // 0-indexed, [l, r)
    int l, r, m;
    T mn, mx;
    Seg *ch[2];
    Seg () = default;
    Seg (int _l, int _r, vector <T> &pre) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, pre);
            ch[1] = new Seg(m, r, pre);
            pull();
        } else {
            mn = mx = pre[l];
        }
    }
    void pull() {
        mn = min(ch[0]->mn, ch[1]->mn);
        mx = max(ch[0]->mx, ch[1]->mx);
    }
    T querymn(int a, int b) {
        if (a <= l && r <= b)
            return mn;
        T ans = 1ll << 60;
        if (a < m)
            ans = min(ans, ch[0]->querymn(a, b));
        if (m < b)
            ans = min(ans, ch[1]->querymn(a, b));
        return ans;
    }
    T querymx(int a, int b) {
        if (a <= l && r <= b)
            return mx;
        T ans = -1ll << 60;
        if (a < m)
            ans = max(ans, ch[0]->querymx(a, b));
        if (m < b)
            ans = max(ans, ch[1]->querymx(a, b));
        return ans;
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <lli> pre(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> a[i], pre[i + 1] = pre[i] + a[i];
        set <int> pos;
        Seg <lli> root(0, n + 1, pre);
        vector <int> p(n);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j) {
            return a[i] > a[j];
        });
        pos.insert(-1), pos.insert(n);
        bool ans = true;
        for (int i : p) {
            int r = *pos.lower_bound(i), l = *prev(pos.lower_bound(i));
            if (l + 1 < i && pre[i] - root.querymn(l + 1, i) > 0)
                ans = false;
            if (i + 2 < r + 1 && root.querymx(i + 2, r + 1) - pre[i + 1] > 0)
                ans = false;
            pos.insert(i);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}