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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1001, logN = 20, K = 1500;

struct Data {
    lli ans = 0;
    set <int> s;
    int n;
    Data (int _n) : n(_n) {
        s.insert(-1);
        s.insert(_n);
        ans = 1ll * n * (n - 1) / 2;
    }
    void add(int x) {
        assert(!s.count(x));
        auto it = s.lower_bound(x);
        int r = *it, l = *(--it);
        ans -= 1ll * (r - l - 1) * (r - l - 2) / 2;
        s.insert(x);
        ans += 1ll * (x - l - 1) * (x - l - 2) / 2;
        ans += 1ll * (r - x - 1) * (r - x - 2) / 2;
    }
    void del(int x) {
        assert(s.count(x));
        s.erase(x);
        auto it = s.lower_bound(x);
        int r = *it, l = *(--it);
        ans -= 1ll * (x - l - 1) * (x - l - 2) / 2;
        ans -= 1ll * (r - x - 1) * (r - x - 2) / 2;
        ans += 1ll * (r - l - 1) * (r - l - 2) / 2;
    }
};

int get_sz(int n, int m) {
    if (n > m)
        return 2 * m;
    return 2 * n - 1;
}

int main () {
    owo;
    int n, m, q;
    cin >> n >> m >> q;
    int now = 0;
    vector <Data> str;
    for (int i = 0; i + 1 < m; ++i) {
        str.pb(Data(get_sz(m - i, n)));
    }
    for (int i = 0; i + 1 < n; ++i) {
        str.pb(Data(get_sz(n - i, m)));
    }
    lli ans = 0;
    for (Data A : str)
        ans += A.ans;
    ans += n * m;
    set <pii> in;
    while (q--) {
        int x, y;
        cin >> x >> y, --x, --y;
        int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        if (x == y) {
            x1 = 0, y1 = x * 2;
            if (m > 1)
                x2 = m - 1, y2 = x * 2;
        } else if (x > y) {
            x1 = m - 1 + x - y - 1, y1 = 2 * y + 1;
            if (x - y < n - 1)
                x2 = m - 1 + x - y, y2 = 2 * y;
        } else {
            x1 = y - x - 1, y1 = 2 * x + 1;
            if (y - x < m - 1)
                x2 = y - x, y2 = 2 * x;
        }
        if (!in.count({x, y})) {
            if (~x1 && x1 < str.size()) {
                ans -= str[x1].ans;
                str[x1].add(y1);
                ans += str[x1].ans;
            }
            if (~x2 && x2 < str.size()) {
                ans -= str[x2].ans;
                str[x2].add(y2);
                ans += str[x2].ans;   
            }
            in.insert({x, y});
            ans--;
        } else {
            if (~x1 && x1 < str.size()) {
                ans -= str[x1].ans;
                str[x1].del(y1);
                ans += str[x1].ans;
            }
            if (~x2 && x2 < str.size()) {
                ans -= str[x2].ans;
                str[x2].del(y2);
                ans += str[x2].ans;   
            }
            in.erase({x, y});
            ans++;
        }
        cout << ans << '\n';
    }
}