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
const int mod = 1e9 + 7, N = 400005, logN = 18, G = 3;

int bit[N];
 
void add(int p, int v) {
    for (int i = p; i < N; i += i & (-i)) bit[i] += v;
}
 
lli query(int p) {
    lli ans = 0;
    for (int i = p; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <pair <pii, int>> seg(n);
    vector <int> v;
    for (int i = 0; i < n; ++i) cin >> seg[i].X, seg[i].Y = i, v.pb(seg[i].X.X), v.pb(seg[i].X.Y);
    sort(all(v));
    for (int i = 0; i < n; ++i) {
        seg[i].X.X = lower_bound(all(v), seg[i].X.X) - v.begin() + 3;
        seg[i].X.Y = lower_bound(all(v), seg[i].X.Y) - v.begin() + 3;
    }
    sort(all(seg), [](pair<pii, int> a, pair<pii,int> b) {
        if (a.X.X == b.X.X) return a.X.Y > b.X.Y;
        return a.X.X < b.X.X;
    });
    vector <int> ans(n, 0);
    for (int i = n - 1; ~i; --i) {
        ans[seg[i].Y] = query(seg[i].X.Y);
        add(seg[i].X.Y, 1);
    }
    for (int i : ans)
        cout << i << '\n';
}