#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int mod = 998244353, N = 4e5 + 7, B = 550;

void solve() {
    int n;
    cin >> n;
    vector <int> p(n), q(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i], q[p[i]] = i;
    ll ans = 1;
    int l = q[0], r = q[0];
    vector <bool> vis(n + 2, false);
    vis[0] = true;
    int mex = 1;
    for (int i = 1; i < n; ++i) {
        if (mex == i) {
            int len = r - l + 1, oth = q[mex];
            int tl = (oth < l ? l - oth : l + 1), tr = (r < oth ? oth - r : n - r);
            int bound = mex * 2 - len;
            // len + x + y <= bound
            // x < tl, y < tr, x + y <= bound - len
            if (bound >= 0) {
                if (tl > tr)
                    swap(tl, tr);
                tl--, tr--;
                bound = min(bound, tl + tr);
                if (bound <= tl)
                    ans += 1ll * (bound + 1) * (bound + 2) / 2;
                else if (bound <= tr)
                    ans += 1ll * (tl + 1) * (tl + 2) / 2 + 1ll * (bound - tl) * (tl + 1);
                else {
                    int x = tl + tr - bound;
                    ans += 1ll * (tl + 1) * (tr + 1) - 1ll * x * (x + 1) / 2;
                }
            }
        }
        int pos = q[i];
        while (pos < l) {
            --l, vis[p[l]] = true;
        }
        while (r < pos) {
            ++r, vis[p[r]] = true;
        }
        while (vis[mex])
            mex++;
    }
    cout << ans << '\n';
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}