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
const int mod = 998244353, N = 300001, logN = 20, K = 111;

int main () {
    owo;
    int n;
    cin >> n;
    vector <vector <int>> adj(n);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    stack <int> stk;
    for (int i = n - 1; ~i; --i) {
        while (!stk.empty() && a[i] > a[stk.top()]) stk.pop();
        if (!stk.empty()) adj[i].pb(stk.top());
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = n - 1; ~i; --i) {
        while (!stk.empty() && a[i] < a[stk.top()]) stk.pop();
        if (!stk.empty()) adj[i].pb(stk.top());
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && a[stk.top()] > a[i]) stk.pop();
        if (!stk.empty()) adj[stk.top()].pb(i);
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && a[stk.top()] < a[i]) stk.pop();
        if (!stk.empty()) adj[stk.top()].pb(i);
        stk.push(i);
    }
    for (int i = 0; i + 1 < n; ++i) adj[i].pb(i + 1);
    vector <int> dp(n, 1 << 30);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    cout << dp[n - 1] << endl;
}