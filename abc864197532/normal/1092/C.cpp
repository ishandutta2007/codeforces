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
    int n;
    cin >> n;
    vector <string> s(2 * n - 2);
    for (int i = 0; i < 2 * n - 2; ++i)
        cin >> s[i];
    vector <int> p(2 * n - 2);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return s[i] < s[j];
    });
    string res;
    auto chk = [&](string ans) {
        res.resize(2 * n - 2);
        vector <pair <string, char>> tmp;
        for (int i = 1; i < ans.length(); ++i) {
            tmp.eb(ans.substr(0, i), 'P'), tmp.eb(ans.substr(i), 'S');
        }
        sort(all(tmp));
        for (int i = 0; i < p.size(); ++i) {
            if (tmp[i].X != s[p[i]]) {
                return false;
            }
            res[p[i]] = tmp[i].Y;
        }
        return true;
    };
    for (int i = 1; i < 2 * n - 2; ++i) if (s[i].length() + s[0].length() == n) {
        if (chk(s[i] + s[0]))
            return cout << res << endl, 0;
        if (chk(s[0] + s[i]))
            return cout << res << endl, 0;
    }
}