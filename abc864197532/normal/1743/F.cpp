#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 19, B = 550;

struct mat {
    int n;
    long long mod2;
    vector <vector <long long>> val;
    mat () = default;
    mat (int _n, int _mode = 0) : n(_n), mod2(1ll * mod * mod) {
        // mode 1 -> I, other -> O
        val.assign(n, vector<long long>(n, 0));
        if (_mode == 1) {
            for (int i = 0; i < n; ++i) val[i][i] = 1;
        }
    }
    mat (const mat& M) : n(M.n), mod2(1ll * mod * mod) {
        val.assign(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                val[i][j] = M.val[i][j];
            }
        }
    }
    mat (vector <vector <long long>> v) : n(v.size()), mod2(1ll * mod * mod), val(v) {}
    mat operator + (const mat& o) {
        mat ans(o);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans.val[i][j] += val[i][j];
                if (ans.val[i][j] >= mod) ans.val[i][j] -= mod;
            }
        }
        return ans;
    }
    mat operator * (const mat& o) {
        mat ans(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                for (int j = 0; j < n; ++j) {
                    ans.val[i][j] += val[i][k] * o.val[k][j];
                    if (ans.val[i][j] >= mod2) ans.val[i][j] -= mod2;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans.val[i][j] %= mod;
            }
        }
        return ans;
    }
    mat operator ^ (long long k) {
        mat ans(n, 1), a(*this);
        for (; k; k >>= 1, a = a * a) {
            if (k & 1) ans = ans * a;
        }
        return ans;
    }
};

mat M0({{3, 1}, {0, 2}}), M1({{1, 1}, {2, 2}});

mat tree[N << 1];

void build() {
    for (int i = N - 1; i; --i) {
        tree[i] = tree[i << 1] * tree[i << 1 | 1];
    }
}

void modify(int p, mat v) {
    for (tree[p += N] = v, p >>= 1; p; p >>= 1) {
        tree[p] = tree[p << 1] * tree[p << 1 | 1];
    }
}

vector <pii> event[N];

void solve() {
    int n;
    cin >> n;
    vector <pii> range(n);
    for (int i = 0; i < n; ++i)
        cin >> range[i], range[i].Y++, event[range[i].X].eb(i, 1), event[range[i].Y].eb(i, -1);
    for (int i = 0; i < n - 1; ++i)
        tree[i + N] = M0;
    for (int i = n - 1; i < N; ++i)
        tree[i + N] = mat(2, 1);
    build();
    ll ans = 0;
    int fr = 0;
    for (int i = 0; i < 300001; ++i) {
        for (auto [x, y] : event[i]) {
            if (y == 1) {
                if (x == 0)
                    fr = 1;
                else
                    modify(n - x - 1, M1);
            } else {
                if (x == 0)
                    fr = 0;
                else
                    modify(n - x - 1, M0);
            }
        }
        ans += tree[1].val[1][fr];
    }
    cout << ans % mod << '\n';
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}