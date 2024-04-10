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
const int mod = 1e9 + 7, N = 150001, logN = 20, K = 48763;

int main () {
    owo;
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector <int> pre(n + 1);
    int mn = 0;
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1), mn = min(mn, pre[i + 1]);
    vector <vector <int>> range(n + 1), pre2(n + 1);
    for (int i = 0; i <= n; ++i)
        pre2[i].pb(0);
    for (int i = 0; i <= n; ++i)
        pre[i] -= mn, range[pre[i]].pb(i);
    vector <int> p(n + 1);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        if (pre[i] == pre[j])
            return i < j;
        return pre[i] < pre[j];
    });
    set <int> se;
    vector <int> len(n + 2, 0);
    test(pre);
    for (int i : p) {
        auto it = se.lower_bound(i);
        int pt = it == se.end() ? n + 1 : *it;
        len[i + 1] = lower_bound(all(range[pre[i]]), pt) - lower_bound(all(range[pre[i]]), i) - 1;
        pre2[pre[i]].pb(pre2[pre[i]].back() + len[i + 1]);
        se.insert(i);
    }
    test(len);
    for (int i = 1; i <= n; ++i) {
        len[i] += len[i - 1];
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r, --l;
        int x = lower_bound(all(range[pre[l]]), l) - range[pre[l]].begin();
        int cnt = lower_bound(all(range[pre[l]]), r) - lower_bound(all(range[pre[l]]), l);
        cout << len[r] - len[l] + 1ll * cnt * (cnt + 1) / 2 - (pre2[pre[l]][x + cnt] - pre2[pre[l]][x]) << endl;
    }
}