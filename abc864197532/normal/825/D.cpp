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
const int mod = 998244353, N = 1000, logC = 30, logN = 19, K = 111, M = 4e6;

int main () {
    owo;
    string s, t;
    cin >> s >> t;
    vector <int> cnt1(26, 0), cnt2(26, 0);
    int Q = 0;
    for (char c : s) {
        if (c == '?') Q++;
        else cnt1[c - 'a']++;
    }
    for (char c : t) cnt2[c - 'a']++;
    for (int i = 1; ; ++i) {
        vector <int> need(26, 0);
        for (int j = 0; j < 26; ++j) need[j] = max(cnt2[j] * i - cnt1[j], 0);
        if (accumulate(all(need), 0) > Q) {
            for (int j = 0; j < 26; ++j) need[j] = max(cnt2[j] * (i - 1) - cnt1[j], 0);
            for (char &c : s) {
                if (c == '?') {
                    for (int j = 0; j < 26; ++j) if (need[j] || j == 25) {
                        cout << char('a' + j);
                        need[j]--;
                        break;
                    }
                } else {
                    cout << c;
                }
            }
            return 0;
        }
    }
}