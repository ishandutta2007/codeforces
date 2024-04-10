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
const int mod = 1e9 + 7, N = 2520, logN = 20, K = 350;

int a[3][3], b[3][3], r[N];

int main () {
    owo;
    lli n;
    int A, B;
    cin >> n >> A >> B, --A, --B;
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) cin >> a[i][j], --a[i][j];
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) cin >> b[i][j], --b[i][j];
    lli ansa = 0, ansb = 0, suma = 0, sumb = 0;
    map <pii, int> m1;
    int all = 0, pre;
    for (int i = 0;; ++i) {
        if ((A + 1) % 3 == B) r[i] = -1;
        if (A == (B + 1) % 3) r[i] = 1;
        m1[{A, B}] = i;
        all++;
        tie(A, B) = mp(a[A][B], b[A][B]);
        if (m1.count({A, B})) {
            pre = m1[{A, B}];
            break;
        }
    }
    test(pre, all);
    for (int i = 0; i < pre && n; ++i) {
        n--;
        if (r[i] == 1) ansa++;
        if (r[i] == -1) ansb++;
    }
    for (int i = pre; i < all; ++i) {
        if (r[i] == 1) suma++;
        if (r[i] == -1) sumb++;
        if (i - pre < n % (all - pre)) {
            if (r[i] == 1) ansa++;
            if (r[i] == -1) ansb++;
        }
    }
    all -= pre;
    cout << ansa + suma * (n / all) << ' ' << ansb + sumb * (n / all) << endl;
}