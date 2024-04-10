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
const int N = 100001, logN = 18, K = 1000, bound = (1 << 30) - 1;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector <int> pt(26, -1);
        for (int i = 0; i < n; ++i) pt[s[i] - 'a'] = i;
        string order;
        while (true) {
            int id = -1;
            for (int i = 0; i < 26; ++i) if (pt[i] != -1 && (id == -1 || pt[id] > pt[i])) {
                id = i;
            }
            if (id == -1) break;
            order.pb('a' + id);
            pt[id] = -1;
        }
        int len = 0;
        for (int i = order.size() - 1; ~i; --i) {
            int cnt = count(all(s), order[i]);
            len += cnt / (i + 1);
        }
        string chk, cur = s.substr(0, len);
        for (char c : order) {
            chk += cur;
            string tmp;
            for (char cc : cur) if (cc != c) tmp.pb(cc);
            cur = tmp;
        }
        if (chk == s) cout << s.substr(0, len) << ' ' << order << endl;
        else cout << -1 << endl;
    }
}