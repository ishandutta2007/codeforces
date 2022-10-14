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
const int mod = 1e9 + 7, N = 8001, logC = 30, logN = 19, K = 111, M = 4e6;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector <int> cnt(10, 0);
        for (char c : s) cnt[c - '0'] ^= 1;
        int n = s.length();
        string ans = string(n - 2, '9');
        for (int i = n - 1; ~i; --i) {
            int oth = n - i - 1;
            cnt[s[i] - '0'] ^= 1;
            for (int a = s[i] - '0' - 1; a >= !i; --a) {
                cnt[a] ^= 1;
                if (oth >= accumulate(all(cnt), 0)) {
                    ans = s.substr(0, i);
                    ans.pb('0' + a);
                    int nine = oth - accumulate(all(cnt), 0);
                    while (nine--) ans.pb('9');
                    for (int i = 9; ~i; --i) if (cnt[i]) ans.pb('0' + i);
                    break;
                }
                cnt[a] ^= 1;
            }
            if (ans.length() == n) break;
        }
        cout << ans << endl;
    }
}