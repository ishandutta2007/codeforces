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
const int mod = 998244353, N = 200087, logN = 19, K = 111, M = 1000006, C = 500;

template <typename T>
struct BIT {
    // single point add, prefix query sum
    const int offset = 3;
    vector <T> val;
    int n;
    BIT (int _n) : n(_n + offset * 2) {
        val.assign(n, 0);
    }
    void add(int p, T v) {
        for (p += offset; p < n; p += p & (-p))
            val[p] += v;
    }
    T query(int p) {
        T ans = 0;
        for (p += offset; p > 0; p -= p & (-p))
            ans += val[p];
        return ans;
    }
    T query(int l, int r) {
        // query [l, r)
        return query(r - 1) - query(l - 1);
    }
    int kth (int k) {
        // 1-index, return kth smallest number
        // 1 <= k && k <= current size
        int ans = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (ans + i < n && val[ans + i] < k) k -= val[ans += i];
        }
        return ans - offset + 1;
    }
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    BIT <int> row(n), col(n);
    vector <int> crow(n), ccol(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y, --x, --y;
            crow[x]++, ccol[y]++;
            if (crow[x] == 1)
                row.add(x, 1);
            if (ccol[y] == 1)
                col.add(y, 1);
        } else if (t == 2) {
            int x, y;
            cin >> x >> y, --x, --y;
            if (crow[x] == 1)
                row.add(x, -1);
            if (ccol[y] == 1)
                col.add(y, -1);
            crow[x]--, ccol[y]--;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2, --x1, --y1;
            if (row.query(x1, x2) == x2 - x1 || col.query(y1, y2) == y2 - y1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}