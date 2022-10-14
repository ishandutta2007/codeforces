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
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 8001, logC = 30, logN = 19, K = 111, M = 4e6;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector <string> t = s;
    for (string &a : t) sort(all(a));
    for (int i = 0; i + 1 < n; ++i) if (t[i] != t[i + 1]) return cout << -1 << endl, 0;
    int p = -1;
    for (int i = 0; i + 1 < n; ++i) if (s[i] != s[i + 1]) {
        p = i;
        break;
    }
    bool is = true;
    for (int i = 0; i < m; ++i) for (int j = i + 1; j < m; ++j) is &= s[0][i] != s[0][j];
    auto check = [&](int p) {
        for (int i = 0; i < n; ++i) if (i ^ p) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) cnt += s[i][j] != s[p][j];
            if (is) {
                if (cnt != 2) return false;
            } else {
                if (cnt != 0 && cnt != 2) return false;
            }
        }
        return true;
    };
    if (p == -1) {
        swap(s[0][0], s[0][1]);
        cout << s[0] << endl;
    } else {
        int q = p + 1;
        vector <int> pos;
        for (int i = 0; i < m; ++i) if (s[p][i] != s[q][i]) pos.pb(i);
        if (!is) {
            if (check(p)) {
                cout << s[p] << endl;
                return 0;
            }
        }
        vector <int> ch(26, -1);
        for (int i = 0; i < m; ++i) if (s[p][i] == s[q][i]) {
            ch[s[p][i] - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i) if (~ch[i]) {
            for (int j = 0; j < pos.size(); ++j) if (s[p][pos[j]] == 'a' + i) {
                pos.pb(ch[i]);
                break;
            }
        }
        if (pos.size() <= 8) {
            for (int i = 0; i < pos.size(); ++i) {
                for (int j = i + 1; j < pos.size(); ++j) {
                    swap(s[p][pos[i]], s[p][pos[j]]);
                    test(s[p]);
                    if (check(p)) {
                        cout << s[p] << endl;
                        return 0;
                    }
                    swap(s[p][pos[i]], s[p][pos[j]]);
                }
            }
        }
        cout << -1 << endl;
    }
}