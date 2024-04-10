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
const int mod = 998244353, N = 1000002, M = 150000, logN = 20, K = 1000;

int ask(vector <pii> a) {
    cout << "? " << a.size() << endl;
    for (pii i : a) cout << i.X << ' ' << i.Y << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

vector <pii> rec(vector <pii> a) {
    int w = -1, h = -1, res = 1 << 30;
    for (int i = 1; i <= 200; ++i) for (int j = 1; j <= 200; ++j) {
        map <int, int> m1;
        for (pii A : a) {
            vector <int> x = {A.X / i}, y = {A.Y / j};
            if (A.X % i != 0) x.pb(x.back() + 1);
            if (A.Y % j != 0) y.pb(y.back() + 1);
            for (int I : x) for (int J : y) m1[I * J]++;
        }
        pii mx = mp(-1, -1);
        for (pii A : m1) mx = max(mx, mp(A.Y, A.X));
        if (res > mx.X) {
            res = mx.X;
            w = i, h = j;
        }
    }
    vector <pii> v;
    for (int i = w; i <= 200; i += w) for (int j = h; j <= 200; j += h) {
        v.eb(i, j);
    }
    res = ask(v);
    vector <pii> b;
    for (pii A : a) {
        vector <int> x = {A.X / w}, y = {A.Y / h};
        if (A.X % w != 0) x.pb(x.back() + 1);
        if (A.Y % h != 0) y.pb(y.back() + 1);
        for (int I : x) for (int J : y) {
            if (I * J == res) b.pb(A);
        }
    }
    return b;
}

void solve() {
    vector <pii> possible_ans;
    vector <pii> v;
    for (int i = 1; i <= 200; ++i) for (int j = 1; j <= 200; ++j) v.eb(i, j);
    int area = ask(v);
    for (int i = 1; i <= 200; ++i) if (area % i == 0) {
        possible_ans.eb(i, area / i);
    }
    while (possible_ans.size() > 1) {
        possible_ans = rec(possible_ans);
    }
    cout << "! " << (possible_ans[0].X + possible_ans[0].Y) * 2 - 4 << endl;
}

int main () {
    owo;
    int t = 1;
    while (t--) {
        solve();
    }
}