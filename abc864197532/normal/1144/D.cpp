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
const int mod = 998244353, N = 60, logN = 19, K = 1 << 9, G = 3;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(200001, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i], cnt[a[i]]++;
    }
    int p = max_element(all(cnt)) - cnt.begin();
    int q = find(all(a), p) - a.begin();
    vector <pair <int, pii>> ans;
    for (int i = q - 1; ~i; --i) if (a[i] != p) {
        if (a[i] < p) {
            ans.pb(mp(1, mp(i, i + 1)));
        } else {
            ans.pb(mp(2, mp(i, i + 1)));
        }
    }
    for (int i = q + 1; i < n; ++i) if (a[i] != p) {
        if (a[i] < p) {
            ans.pb(mp(1, mp(i, i - 1)));
        } else {
            ans.pb(mp(2, mp(i, i - 1)));
        }
    }
    cout << ans.size() << endl;
    for (auto a : ans) {
        cout << a.X << ' ' << a.Y.X + 1 << ' ' << a.Y.Y + 1 << endl;
    }
}