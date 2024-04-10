#include <bits/stdc++.h>
using namespace std;
#define lli int_fast64_t
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
const int mod = 998244353, N = 100005, logN = 18, C = 512;

int x[N], v[N];
lli p[N][2], p100[101], p100inv[101];

struct Seg {
    int l, r, m;
    lli val[2][2];
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        } else {
            for (int i : {0, 1}) for (int j : {0, 1}) {
                val[i][j] = p100[p[l][i]] * p100[p[r][j]] % mod;
            }
        }
    }
    void pull() {
        for (int i : {0, 1}) for (int j : {0, 1}) {
            val[i][j] = 0;
            for (int k : {0, 1}) {
                val[i][j] += ch[0]->val[i][k] * ch[1]->val[k][j] % mod * p100inv[p[m][k]] % mod;
            }
            if (val[i][j] >= mod)
                val[i][j] -= mod;
        }
    }
    void modify(int p, vector <lli> v) {
        if (r - l == 1) 
            val[0][0] = v[0], val[0][1] = v[1], val[1][0] = v[2], val[1][1] = v[3];
        else
            ch[p >= m]->modify(p, v), pull();
    }
    vector <lli> modify2(int pos, int a, int b) {
        if (r - l == 1) {
            vector <lli> v = {val[0][0], val[0][1], val[1][0], val[1][1]};
            val[0][0] = val[0][1] = val[1][0] = val[1][1] = 0;
            val[a][b] = p100[p[l][a]] * p100[p[r][b]] % mod;
            return v;
        } else {
            auto tmp = ch[pos >= m]->modify2(pos, a, b);
            pull();
            return tmp;
        }
    }
};

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
    for (int i = 0; i <= 100; ++i) {
        p100[i] = modpow(100, mod - 2) * i % mod;
        p100inv[i] = modpow(i, mod - 2) * 100 % mod;
    }
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> v[i] >> p[i][1];
        p[i][0] = 100 - p[i][1];
    }
    Seg root(0, n - 1);
    vector <array <int, 6>> event;
    for (int i = 1; i < n; ++i) {
        // 10
        event.pb({x[i] - x[i - 1], v[i] + v[i - 1], i - 1, 1, i, 0});
        // 00
        if (v[i - 1] < v[i])
            event.pb({x[i] - x[i - 1], v[i] - v[i - 1], i - 1, 0, i, 0});
        // 11
        if (v[i - 1] > v[i])
            event.pb({x[i] - x[i - 1], v[i - 1] - v[i], i - 1, 1, i, 1});
    }
    sort(all(event), [&](array<int, 6> i, array<int, 6> j) {
        return 1ll * i[0] * j[1] < 1ll * i[1] * j[0];
    });
    lli ans = 0;
    for (auto i : event) {
        vector <lli> tmp = root.modify2(i[2], i[3], i[5]);
        for (int j : {0, 1}) for (int k : {0, 1}) {
            (ans += root.val[j][k] * i[0] % mod * modpow(i[1], mod - 2)) %= mod;
        }
        tmp[i[3] * 2 + i[5]] = 0;
        root.modify(i[2], tmp);
    }
    cout << ans << '\n';
}