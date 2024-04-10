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
const int mod = 1e9 + 7, N = 200087, logN = 18, K = 1000;

struct Dsu {
    int dsu[N], size[N], n, cc;
    Dsu (int _n) : n(_n), cc(_n) {
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int v) {
        if (dsu[v] == v) return v;
        return dsu[v] = Find(dsu[v]);
    }
    bool Union(int v, int u) {
        int x = Find(v), y = Find(u);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        dsu[x] = y;
        size[y] += size[x];
        size[x] = 0;
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

int main () {
    owo;
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    Dsu dsu1(n), dsu2(n);
    for (int i = 0, u, v; i < m1; ++i) {
        cin >> u >> v, --u, --v;
        dsu1.Union(u, v);
    }
    for (int i = 0, u, v; i < m2; ++i) {
        cin >> u >> v, --u, --v;
        dsu2.Union(u, v);
    }
    vector <pii> v;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        if (!dsu1.same(i, j) && !dsu2.same(i, j)) {
            v.eb(i, j);
            dsu1.Union(i, j);
            dsu2.Union(i, j);
        }
    }
    cout << v.size() << endl;
    for (pii A : v) cout << A.X + 1 << ' ' << A.Y + 1 << endl;
}