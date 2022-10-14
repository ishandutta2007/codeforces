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
const int mod = 1e9 + 7, N = 300001, logN = 19, K = 1 << 9;

int main() {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> cnt(m, 0), pre(m + 1, 0);
    vv <int> pre2(m + 1, logN, 0);
    for (int i = 0, x; i < n; ++i) {
        cin >> x, cnt[--x] ^= 1;
    }
    for (int i = 0; i < m; ++i) {
        pre[i + 1] = pre[i] ^ cnt[i];
    }
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i + (1 << j) <= m; ++i) {
            pre2[i][j] = pre2[i][j - 1] ^ pre2[i + (1 << j - 1)][j - 1];
            if (pre[i + (1 << j)] != pre[i + (1 << j - 1)])
                pre2[i][j] ^= 1 << j - 1;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r, --l;
        int xorr = 0, bit = 0;
        for (int k = logN - 1; ~k; --k) if (l + (1 << k) <= r) {
            xorr ^= pre2[l][k];
            if (pre[l + (1 << k)] != pre[l]) {
                xorr ^= bit;
            }
            bit |= 1 << k;
            l += 1 << k;
        }
        cout << "AB"[xorr == 0];
    }
}