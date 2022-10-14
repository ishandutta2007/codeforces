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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000001, logN = 20, K = 111;

int main () {
    owo;
    int n;
    string s;
    cin >> n >> s;
    vector <int> l0(n, -1), r0(n, n), l1(n, -1), r1(n, n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            l0[i] = r0[i] = i;
        if (s[i] == '1')
            l1[i] = r1[i] = i;
    }
    for (int i = n - 2; ~i; --i) {
        r0[i] = min(r0[i], r0[i + 1]);
        r1[i] = min(r1[i], r1[i + 1]);
    }
    for (int i = 1; i < n; ++i) {
        l0[i] = max(l0[i], l0[i - 1]);
        l1[i] = max(l1[i], l1[i - 1]);
    }
    for (int d = 1; d <= n; ++d) {
        int now = 0, ans = 0;
        while (now + d <= n) {
            if (r0[now] >= now + d || r1[now] >= now + d) {
                now += d;
                ans++;
            } else {
                int nxt = now + d - 1;
                int res = n + 1;
                if (r0[nxt] - l0[nxt] - 1 >= d) {
                    res = min(res, l0[nxt]);
                }
                if (r1[nxt] - l1[nxt] - 1 >= d) {
                    res = min(res, l1[nxt]);
                }
                if (res == n + 1) {
                    now += d;
                } else {
                    now = res + d + 1;
                    ans++;
                }
            }
        }
        cout << ans << ' ';
    }
}