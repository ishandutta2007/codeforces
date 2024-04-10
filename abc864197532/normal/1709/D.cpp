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
const int mod = 998244353, N = 200005, logN = 18, G = 3;

template <typename T>
struct SparseTableMax {
    // 0-indexed, [l, r)
    vector <vector <T>> table;
    SparseTableMax () = default;
    SparseTableMax (vector <T> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <T> (m, 0));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = max(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        if (l >= r)
            return -1 << 30;
        int g = __lg(r - l);
        return max(table[l][g], table[r - (1 << g)][g]);
    }
};

int main () {
    owo;
    int n, m, q;
    cin >> n >> m;
    vector <int> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    SparseTableMax <int> ST(a);
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        if ((x2 - x1) % k || (y2 - y1) % k) {
            cout << "NO\n";
        } else {
            int mx = ST.query(min(y1, y2) - 1, max(y1, y2));
            if (x1 > mx) {
                cout << "YES\n";
            } else {
                x1 += (mx - x1) / k * k;
                while (x1 <= mx)
                    x1 += k;
                if (x1 > n) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }
            }
        }
    }
}