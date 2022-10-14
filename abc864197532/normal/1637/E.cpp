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
const int mod = 1e9 + 7, N = 1e5 + 87, logN = 20, K = 111, M = N * 20;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> cnt_to_x(n + 1);
        map <int, int> cnt;
        for (int i = 0, x; i < n; ++i) {
            cin >> x, cnt[x]++;
        }
        map <int, vector <int>> bad;
        for (int i = 0, x, y; i < m; ++i) {
            cin >> x >> y, bad[x].pb(y), bad[y].pb(x);
        }
        vector <vector <bool>> is(n + 1);
        for (pii A : cnt)
            cnt_to_x[A.Y].pb(A.X), is[A.Y].pb(false);
        for (int i = 0; i < n; ++i)
            sort(all(cnt_to_x[i]));
        lli ans = 0;
        for (auto [x, c] : cnt) {
            is[c][lower_bound(all(cnt_to_x[c]), x) - cnt_to_x[c].begin()] = true;
            for (int y : bad[x]) {
                int c = cnt[y];
                is[c][lower_bound(all(cnt_to_x[c]), y) - cnt_to_x[c].begin()] = true;
            }
            for (int cy = 1; cy <= c; ++cy) {
                for (int i = cnt_to_x[cy].size() - 1; ~i; --i) if (!is[cy][i]) {
                    ans = max(ans, 1ll * (cy + c) * (x + cnt_to_x[cy][i]));
                    break;
                }
            }
            is[c][lower_bound(all(cnt_to_x[c]), x) - cnt_to_x[c].begin()] = false;
            for (int y : bad[x]) {
                int c = cnt[y];
                is[c][lower_bound(all(cnt_to_x[c]), y) - cnt_to_x[c].begin()] = false;
            }
        }
        cout << ans << '\n';
    }
}