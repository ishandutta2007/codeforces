/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 17, logN = 19, K = 1 << 9, G = 3;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> a(n), l(m), r(m), idl(m), idr(m);
    vector <int> v = {0, n};
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> l[i] >> r[i], --l[i], v.pb(l[i]), v.pb(r[i]);
    sort(all(v)), v.resize(unique(all(v)) - v.begin());
    for (int i = 0; i < m; ++i) {
        idl[i] = lower_bound(all(v), l[i]) - v.begin();
        idr[i] = lower_bound(all(v), r[i]) - v.begin();
    }
    vector <int> pre(v.size() - 1, 1 << 30);
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = v[i]; j < v[i + 1]; ++j) {
            pre[i] = min(pre[i], a[j]);
        }
    }
    int ans = -1 << 30;
    vector <int> way;
    for (int i = 0; i < n; ++i) {
        vector <int> tmp, cur(v.size(), 0);
        for (int j = 0; j < m; ++j) if (!(l[j] <= i && i < r[j])) {
            tmp.pb(j + 1);
            cur[idl[j]]--;
            cur[idr[j]]++;
        }
        int mn = pre[0] + cur[0];
        for (int i = 1; i + 1 < v.size(); ++i) {
            cur[i] += cur[i - 1];
            mn = min(mn, pre[i] + cur[i]);
        }
        if (ans < a[i] - mn) {
            ans = a[i] - mn;
            way = tmp;
        }
    }
    cout << ans << endl << way.size() << endl;
    printv(all(way));
}