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
const int mod = 998244353, N = 1000001, logN = 18, G = 3;

int a[N], pre[N], l[N], r[N], ans[N], mx[N];

int main () {
    owo;
    pre[0] = 0;
    for (int i = 1; i < N; ++i)
        pre[i] = pre[i - 1] ^ i;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i)
        cin >> l[i] >> r[i], --l[i], --r[i];
    auto f = [&](int x, int y) {
        if (x > y) swap(x, y);
        return pre[y] ^ pre[x - 1];
    };
    for (int i = 0; i < n; ++i) {
        fill(mx, mx + n, 0);
        mx[i] = a[i];
        for (int j = i + 1; j < n; ++j) {
            mx[j] = max(mx[j - 1], f(a[i], a[j]));
        }
        for (int id = 0; id < q; ++id) if (l[id] <= i) {
            ans[id] = max(ans[id], mx[r[id]]);
        }
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}