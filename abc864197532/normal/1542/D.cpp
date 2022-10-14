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
const int mod = 998244353, N = 100001, logN = 20, K = 111;

int main () {
    srand(time(NULL));
    owo;
    int n;
    cin >> n;
    vector <int> v;
    char c;
    for (int i = 0, x; i < n; ++i) {
        cin >> c;
        if (c == '+') cin >> x, v.pb(x);
        else v.pb(-1);
    }
    lli ans = 0;
    for (int st = 0; st < n; ++st) if (v[st] != -1) {
        vector <int> a;
        int times = 1;
        for (int i = 0; i < n; ++i) {
            if (i == st) a.pb(0);
            else if (v[i] == -1) a.pb(-1);
            else if (v[i] < v[st] || (v[i] == v[st] && i < st)) a.pb(1);
            else {
                times += times;
                if (times >= mod) times -= mod;
            }
        }
        vector <int> dp(n + 1, 0);
        dp[0] = 1;
        bool is = false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == 0) {is = true; continue;}
            vector <int> nxt = dp;
            if (is) {
                for (int j = 0; j < n; ++j) {
                    if (j + a[i] >= 0) {
                        nxt[j + a[i]] += dp[j];
                        if (nxt[j + a[i]] >= mod) nxt[j + a[i]] -= mod;
                    }
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    int nj = max(j + a[i], 0);
                    nxt[nj] += dp[j];
                    if (nxt[nj] >= mod) nxt[nj] -= mod;
                }
            }
            dp = nxt;
        }
        int cnt = 0;
        for (int i = 0; i < n + 1; ++i) {
            cnt += dp[i];
            if (cnt >= mod) cnt -= mod;
        }
        (ans += 1ll * cnt * v[st] % mod * times) %= mod;
    }
    cout << ans << endl;
    /*
    int tans = 0;
    for (int s = 0; s < 1 << n; ++s) {
        priority_queue <int> pq;
        for (int i = 0; i < n; ++i) if (s >> i & 1) {
            if (v[i] != -1) pq.push(-v[i]), tans += v[i];
            else if (!pq.empty()) tans += pq.top(), pq.pop();
        }
    }
    cout << tans << endl;
     */
}