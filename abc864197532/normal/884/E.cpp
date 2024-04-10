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
const int mod = 1e9 + 7, N = 1 << 14, logN = 20, K = 350;

bool a[N], b[N];
int dsu[N << 1];

int Find(int v) {
    if (dsu[v] == v) return v;
    return dsu[v] = Find(dsu[v]);
}

bool Union(int a, int b) {
    int x = Find(a), y = Find(b);
    if (x == y) return false;
    if (x > y) swap(x, y);
    dsu[x] = y;
    return true;
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < m >> 2; ++i) {
        int now;
        if ('0' <= s[i] && s[i] <= '9') now = s[i] - '0';
        else now = s[i] - 'A' + 10;
        for (int j = 3; ~j; --j) {
            a[i * 4 + 3 - j] = now >> j & 1;
        }
        ans += __builtin_popcount(now);
    }
    for (int i = 0; i < m; ++i) dsu[i] = i;
    for (int i = 1; i < m; ++i) if (a[i] && a[i - 1]) {
        ans -= Union(i - 1, i);
    }
    for (int _ = 1; _ < n; ++_) {
        cin >> s;
        for (int i = 0; i < m >> 2; ++i) {
            int now;
            if ('0' <= s[i] && s[i] <= '9') now = s[i] - '0';
            else now = s[i] - 'A' + 10;
            for (int j = 3; ~j; --j) {
                b[i * 4 + 3 - j] = now >> j & 1;
            }
            ans += __builtin_popcount(now);
        }
        for (int i = 0; i < m; ++i) dsu[i + N] = i + N;
        for (int i = 1; i < m; ++i) if (b[i] && b[i - 1]) {
            ans -= Union(i - 1 + N, i + N);
        }
        for (int i = 0; i < m; ++i) if (a[i] && b[i]) {
            ans -= Union(i, i + N);
        }
        for (int i = 0; i < m; ++i) {
            dsu[i] = dsu[i + N] - N;
            a[i] = b[i];
        }
    }
    cout << ans << endl;
}