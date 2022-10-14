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
const int N = 200000, logN = 18, K = 1000;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        vector <int> ans;
        auto add = [&](int x) {
            ans.pb(x);
            reverse(p.begin(), p.begin() + x);
        };
        bool is = true;
        for (int now = n; now > 1; now -= 2) {
            int f = -1, s = -1;
            for (int i = 0; i < now; ++i) {
                if (p[i] == now - 1) f = i;
                if (p[i] == now) s = i;
            }
            if (f & 1 && s & 1 ^ 1) {
                add(s + 1);
                for (int i = 0; i < now; ++i) {
                    if (p[i] == now - 1) f = i;
                    if (p[i] == now) s = i;
                }
                if (s + 1 != f) {
                    add(f);
                    for (int i = 0; i < now; ++i) {
                        if (p[i] == now - 1) f = i;
                        if (p[i] == now) s = i;
                    }
                }
                add(now);
                for (int i = 0; i < now; ++i) {
                    if (p[i] == now - 1) f = i;
                    if (p[i] == now) s = i;
                }
                add(s + 1);
                add(now);
            } else {
                is = false;
                break;
            }
        }
        if (is) {
            test(p);
            cout << ans.size() << endl;
            printv(all(ans));
        } else {
            cout << -1 << endl;
        }
    }
}