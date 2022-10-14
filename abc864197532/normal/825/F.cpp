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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 8001, logC = 30, logN = 19, K = 111, M = 4e6;

vector <int> build_fail (string s) {
    vector <int> f(s.length() + 1, 0);
    int now = 0;
    for (int i = 1; i < s.length(); ++i) {
        while (now && s[now] != s[i]) now = f[now];
        if (s[now] == s[i]) now++;
        f[i + 1] = now;
    }
    return f;
}

int main () {
    owo;
    string s;
    cin >> s;
    int n = s.length();
    vector <int> dp(n + 1, 1 << 30);
    dp[0] = 0;
    vector <int> chg(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        if (i == 10 || i == 100 || i == 1000) chg[i] = chg[i - 1] + 1;
        else chg[i] = chg[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        vector <int> f = build_fail(s.substr(i));
        test(f, s.substr(i));
        for (int j = i + 1; j <= n; ++j) {
            dp[j] = min(dp[j], dp[i] + 1 + j - i);
            int len = j - i - f[j - i];
            if ((j - i) % len == 0) {
                dp[j] = min(dp[j], dp[i] + chg[(j - i) / len] + len);
            }
        }
    }
    cout << dp[n] << endl;
}