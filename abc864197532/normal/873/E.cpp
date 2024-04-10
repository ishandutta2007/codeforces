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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 100005, logN = 18, G = 3;

template <typename T>
struct SparseTableMax {
    // 0-indexed, [l, r)
    vector <vector <T>> table;
    SparseTableMax () = default;
    SparseTableMax (vector <T> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <T> (m));
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

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector <int> p(n + 1);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return a[i] < a[j];
    });
    vector <pii> d(n);
    for (int i = 0; i < n; ++i)
        d[i] = make_pair(a[p[i + 1]] - a[p[i]], i);
    array <int, 3> ans = {-1, -1, -1};
    auto upd = [&](int i, int j, int k) {
        array <int, 3> res = {i, j, k};
        if (ans[0] == -1) {
            ans = res;
            return;
        }
        for (int i = 2; ~i; --i) {
            if (d[ans[i]].X > d[res[i]].X)
                return;
            if (d[ans[i]].X < d[res[i]].X) {
                ans = res;
                break;
            }
        }
    };
    SparseTableMax <pii> ST(d);
    for (int j = 1; j < n; ++j) for (int k = j + 1; k < n; ++k) {
        int mn = k - j, mx = n - k;
        if (mn > mx)
            swap(mn, mx);
        if (mn * 2 < mx)
            continue;
        /*
         0 <= i < j
         (j - i) * 2 >= mx   i <= j - mx / 2
         mn * 2 >= (j - i)   i >= j - mn * 2
         */
        int l = max(0, j - mn * 2);
        int r = min(j, j - (mx + 1) / 2 + 1);
        if (l < r) {
            auto res = ST.query(l, r);
            upd(res.Y, j, k);
        }
    }
    vector <int> tans(n + 1);
    for (int i = 0; i < ans[0]; ++i)
        tans[p[i + 1]] = -1;
    for (int i = ans[0]; i < ans[1]; ++i)
        tans[p[i + 1]] = 3;
    for (int i = ans[1]; i < ans[2]; ++i)
        tans[p[i + 1]] = 2;
    for (int i = ans[2]; i < n; ++i)
        tans[p[i + 1]] = 1;
    printv(1 + all(tans));
}