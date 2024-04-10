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
const int mod = 1e9 + 7, N = 41, logN = 20, K = 350;

struct val {
    string al;
    lli ans;
    val (string _s = "") : al(_s), ans(0) {
        for (int i = 0; i + 4 <= al.length(); ++i) {
            if (al.substr(i, 4) == "haha") ans++;
        }
    }
    val operator + (const val& o) {
        string l = al, r = o.al;
        for (int i = 3; i >= 1; --i) if (l.length() >= i && r.length() >= 4 - i) {
            if (l.substr(l.length() - i) + r.substr(0, 4 - i) == "haha") ans++;
        }
        al = l + r;
        if (al.length() > 6) {
            al = al.substr(0, 3) + al.substr(al.length() - 3);
        }
        val tans(al);
        tans.ans = ans + o.ans;
        return tans;
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        map <string, val> m1;
        int q;
        cin >> q;
        while (q--) {
            string s, op;
            cin >> s >> op;
            if (op == ":=") {
                string t;
                cin >> t;
                val A = val(t);
                m1[s] = A;
            } else {
                string a, c, b;
                cin >> a >> c >> b;
                val A = m1[a], B = m1[b];
                m1[s] = A + B;
            }
            if (q == 0) cout << m1[s].ans << endl;
        }
    }
}