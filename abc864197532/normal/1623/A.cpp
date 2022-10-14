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
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
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
    if (a.empty())
        return o << "{}";
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
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 5001, logN = 17, M = N * 40;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m, xa, xb, ya, yb, p;
        cin >> n >> m >> xa >> ya >> xb >> yb, --xa, --ya, --xb, --yb;
        p = 1;
        vector <int> x, y;
        if (xa == xb)
            x.pb(0);
        if (ya == yb)
            y.pb(0);
        for (int i = 1, way = 1; i < n * 2 - 2; ++i) {
            if (xa + way == n)
                way = -1;
            if (xa + way == -1)
                way = 1;
            xa += way;
            if (xa == xb) {
                x.pb(i);
            }
        }
        for (int i = 1, way = 1; i < m * 2 - 2; ++i) {
            if (ya + way == m)
                way = -1;
            if (ya + way == -1)
                way = 1;
            ya += way;
            if (ya == yb) {
                y.pb(i);
            }
        }
        vector <lli> pos;
        for (int rx : x) {
            for (lli j = rx, cnt = 0; cnt < 2 * m - 2; ++cnt, j += 2 * n - 2)
                pos.pb(j);
        }
        for (int ry : y) {
            for (lli j = ry, cnt = 0; cnt < 2 * n - 2; ++cnt, j += 2 * m - 2)
                pos.pb(j);
        }
        sort(all(pos));
        pos.resize(unique(all(pos)) - pos.begin());
        lli mu = 1ll * (2 * n - 2) * (2 * m - 2);
        lli ans = 0, cur_pos = 1;
        for (lli i : pos) {
            (ans += cur_pos * p % mod * (i % mod)) %= mod;
            cur_pos = cur_pos * (mod + 1 - p) % mod;
        }
        (ans += cur_pos * (mu % mod)) %= mod;
        cout << ans * modpow(mod + 1 - cur_pos, mod - 2) % mod << endl;
        // E = E1 + (E + mu) * p
        // E * (1 - p) = mu * p + E1;
    }
}