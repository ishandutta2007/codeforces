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
const int mod = 998244353, N = 4e6 + 1, logN = 18, K = 1 << 9, G = 3;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <set <int>> s(n - 1);
        for (int i = 0, sz; i < n - 1; ++i) {
            cin >> sz;
            for (int j = 0, x; j < sz; ++j) {
                cin >> x;
                s[i].insert(x);
            }
        }
        vector <int> ans;
        for (int st = 1; st <= n; ++st) {
            auto re = s;
            for (int i = 0; i < n - 1; ++i) if (re[i].count(st)) {
                re[i].erase(st);
            }
            ans.clear(), ans.pb(st);
            for (int j = 1; j < n; ++j) {
                int p = -1;
                bool is = false;
                for (int i = 0; i < n - 1; ++i) if (re[i].size() == 1) {
                    if (p != -1) {
                        is = true;
                    }
                    p = i;
                }
                if (is || p == -1) {
                    break;
                }
                int x = *re[p].begin();
                ans.pb(x);
                for (int i = 0; i < n - 1; ++i) if (re[i].count(x)) {
                    re[i].erase(x);
                }
            }
            if (ans.size() == n) {
                vector <bool> vis(n - 1, false);
                bool ok = true;
                for (int i = n - 1; i; --i) {
                    int p = -1;
                    bool is = false;
                    for (int j = 0; j < n - 1; ++j) if (!vis[j] && s[j].count(ans[i])) {
                        if (p != -1) {
                            is = true;
                        }
                        p = j;
                    }
                    if (is || p == -1) {
                        ok = false;
                        break;
                    }
                    vis[p] = true;
                    set <int> A;
                    for (int j = i; j > i - int(s[p].size()); --j) {
                        A.insert(ans[j]);
                    }
                    if (A != s[p]) {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    break;
            }
        }
        printv(all(ans));
    }
}