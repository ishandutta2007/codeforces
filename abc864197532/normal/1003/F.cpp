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
const int mod = 998244353, N = 1 << 18, logN = 19, K = 1 << 9, G = 3;

int main () {
    owo;
    int n, _id = 0;
    cin >> n;
    vector <int> a(n), len(n);
    map <string, int> m1;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (!m1.count(s)) {
            m1[s] = _id++;
        }
        len[i] = s.length();
        a[i] = m1[s];
    }
    int ans = 0;
    vv <int> dp(n, n, 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j){
        int d = 0;
        while (i + d < n && j + d < n && a[i + d] == a[j + d])
            d++;
        dp[i][j] = d;
    }
    map <pii, int> m2;
    for (int d = 1; d <= n; ++d) {
        for (int i = 0; i + d <= n; ++i) {
            int tmp = 0;
            for (int k = i; k < i + d; ++k)
                tmp += len[k] - 1;
            int r = -1, res = 0;
            for (int j = 0; j + d <= n; ++j) if (dp[i][j] >= d) {
                if (r <= j) {
                    r = j + d;
                    res++;
                }
            }
            if (res > 1)
                ans = max(ans, (tmp + d - 1) * res);
        }
    }
    cout << accumulate(all(len), 0) + n - 1 - ans << endl;
}