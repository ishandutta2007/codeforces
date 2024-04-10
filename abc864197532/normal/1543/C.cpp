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
const int mod = 998244353, N = 200001, logN = 20, K = 111;

double get() {
    string s;
    cin >> s;
    int n = 6 - s.length(), val = 0;
    for (char c : s) if (c != '.') val = val * 10 + c - '0';
    while (n--) val *= 10;
    return val;
}

double solve(lli a, lli b, lli c, lli v, int t = 1) {
    int alive = 2 - (a == 0) - (b == 0);
    double ans = 0;
    lli all = a + b + c;
    if (a != 0) {
        lli del = min(a, v);
        if (alive == 1) ans += solve(a - del, 0, c + del, v, t + 1) * a / all;
        else ans += solve((a - del) * 2, b * 2 + del, c * 2 + del, v * 2, t + 1) * a / all;
    }
    if (b != 0) {
        lli del = min(b, v);
        if (alive == 1) ans += solve(0, b - del, c + del, v, t + 1) * b / all;
        else ans += solve(a * 2 + del, (b - del) * 2, c * 2 + del, v * 2, t + 1) * b / all;
    }
    ans += double(c) / all * t;
    return ans;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int a = get(), b = get(), c = get(), v = get();
        cout << fixed << setprecision(15) << solve(a, b, c, v) << endl;
    }
}