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
const int mod = 998244353, N = 18, logN = 20;

template <typename T>
struct SparseTableMax {
    // 0-indexed, [l, r)
    vector <vector <T>> table;
    SparseTableMax () = default;
    SparseTableMax (vector <T> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <T> (m, mp(0, 0)));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = max(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        int g = __lg(r - l);
        return max(table[l][g], table[r - (1 << g)][g]);
    }
};

template <typename T>
struct SparseTableMin {
    // 0-indexed, [l, r)
    vector <vector <T>> table;
    SparseTableMin () = default;
    SparseTableMin (vector <T> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <T> (m, mp(0, 0)));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        int g = __lg(r - l);
        return min(table[l][g], table[r - (1 << g)][g]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <pii> pr(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], pr[i] = mp(a[i], i);
    SparseTableMax <pii> STmx(pr);
    SparseTableMin <pii> STmn(pr);
    vector <int> pt(n);
    vector <int> lessbound(n), grebound(n);
    vector <int> stk1, stk2;
    for (int i = n - 1; ~i; --i) {
        while (!stk1.empty() && a[stk1.back()] < a[i])
            stk1.pop_back();
        while (!stk2.empty() && a[stk2.back()] > a[i])
            stk2.pop_back();
        grebound[i] = stk1.empty() ? n : stk1.back();
        lessbound[i] = stk2.empty() ? n : stk2.back();
        stk1.pb(i), stk2.pb(i);
    }
    for (int i = 0; i + 1 < n; ++i) {
        int now;
        if (a[i] > a[i + 1]) {
            // gre
            pii res = STmn.query(i, grebound[i]);
            now = res.Y;
        } else {
            pii res = STmx.query(i, lessbound[i]);
            now = res.Y;
        }
        pt[i] = now;
    }
    int ans = 0;
    int now = 0;
    while (now < n - 1) {
        ans++;
        now = pt[now];
    }
    cout << ans << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}