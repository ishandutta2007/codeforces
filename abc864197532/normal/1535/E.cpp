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
const int mod = 1e9 + 7, N = 300001, logC = 30, logN = 19, K = 550, M = 4e6;

int jump[N][logN];
int a[N], c[N];

int main () {
    owo;
    int q;
    cin >> q >> a[0] >> c[0];
    for (int i = 1, type, v, w; i <= q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> jump[i][0] >> a[i] >> c[i];
            for (int j = 1; j < logN; ++j) {
                if (jump[i][j - 1] == -1) jump[i][j] = -1;
                else jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
        } else {
            cin >> v >> w;
            int ord = v;
            int len = 0;
            for (int j = logN - 1; ~j; --j) {
                if (jump[v][j] == -1) continue;
                if (a[jump[v][j]] > 0) v = jump[v][j], len |= 1 << j;
            }
            int ans1 = 0;
            lli ans2 = 0;
            for (; ~len; --len) {
                int cur = ord;
                for (int j = logN - 1; ~j; --j) if (len >> j & 1) {
                    cur = jump[cur][j];
                }
                int add = min(w, a[cur]);
                a[cur] -= add;
                w -= add;
                ans1 += add;
                ans2 += 1ll * add * c[cur];
                if (w == 0) break;
            }
            cout << ans1 << ' ' << ans2 << endl;
        }
    }
}