#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
const int mod = 1e9 + 7, N = 1 << 19, C = 1e7 + 5;

struct or_convolution {
    void fwt(vector <int> &a) {
        int n = __lg(a.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                if (j >> i & 1) {
                    a[j] += a[j ^ (1 << i)];
                    if (a[j] >= mod) a[j] -= mod;
                }
            }
        }
    }
    void ifwt(vector <int> &a) {
        int n = __lg(a.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                if (j >> i & 1) {
                    a[j] -= a[j ^ (1 << i)];
                    if (a[j] < 0) a[j] += mod;
                }
            }
        }
    }
} OR;

struct and_convolution {
    void fwt(vector <int> &a) {
        int n = __lg(a.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1 << n; ++j) if (j >> i & 1) {
                (a[j ^ (1 << i)] += a[j]) %= mod;
            }
        }
    }
    void ifwt(vector <int> &a) {
        int n = __lg(a.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1 << n; ++j) if (j >> i & 1) {
                (a[j ^ (1 << i)] -= a[j] - mod) %= mod;
            }
        }
    }
} AND;

vector <int> gen(char c) {
    vector <int> val(1 << 16);
    vector <int> num(8, 0);
    for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) for (int c = 0; c < 2; ++c) for (int d = 0; d < 2; ++d) {
        int x = (a << 3) | (b << 2) | (c << 1) | d;
        if (a) num[0] |= 1 << x;
        else num[4] |= 1 << x;
        if (b) num[1] |= 1 << x;
        else num[5] |= 1 << x;
        if (c) num[2] |= 1 << x;
        else num[6] |= 1 << x;
        if (d) num[3] |= 1 << x;
        else num[7] |= 1 << x;
    }
    if ('A' <= c && c <= 'D') val[num[c - 'A']]++;
    else if ('a' <= c && c <= 'd') val[num[c - 'a' + 4]]++;
    else {
        for (int i = 0; i < 8; ++i) val[num[i]]++;
    }
    return val;
}

int ch[N][2];
char val[N];
vector <int> dp[N];

void dfs(int v) {
    int com = 0;
    if (ch[v][0])
        dfs(ch[v][0]), com++;
    if (ch[v][1])
        dfs(ch[v][1]), com++;
    if (com) {
        dp[v].assign(1 << 16, 0);
        vector <int> or_val(1 << 16), and_val(1 << 16);
        {
            vector <int> A = dp[ch[v][0]], B = dp[ch[v][1]];
            OR.fwt(A), OR.fwt(B);
            for (int i = 0; i < 1 << 16; ++i)
                or_val[i] = 1ll * A[i] * B[i] % mod;
            OR.ifwt(or_val);
        }
        {
            vector <int> A = dp[ch[v][0]], B = dp[ch[v][1]];
            AND.fwt(A), AND.fwt(B);
            for (int i = 0; i < 1 << 16; ++i)
                and_val[i] = 1ll * A[i] * B[i] % mod;
            AND.ifwt(and_val);
        }
        if (val[v] != '&') {
            dp[v] = or_val;
        }
        if (val[v] != '|') {
            for (int i = 0; i < 1 << 16; ++i) {
                dp[v][i] += and_val[i];
                if (dp[v][i] >= mod) dp[v][i] -= mod;
            }
        }
    } else {
        dp[v] = gen(val[v]);
    }
}

void solve() {
    string s; cin >> s;
    vector <int> need(16, -1);
    int n; cin >> n;
    for (int i = 0, a, b, c, d, e; i < n; ++i) {
        cin >> a >> b >> c >> d >> e;
        need[(a << 3) | (b << 2) | (c << 1) | d] = e;
    }
    vector <int> path = {0};
    int sz = 1;
    for (char c : s) {
        if (c == '(') {
            int nxt = sz++;
            if (!ch[path.back()][0])
                ch[path.back()][0] = nxt;
            else
                ch[path.back()][1] = nxt;
            path.pb(nxt);
        } else if (c == ')') {
            path.pop_back();
        } else {
            val[path.back()] = c;
        }
    }
    dfs(0);
    int ans = 0;
    for (int s = 0; s < 1 << 16; ++s) {
        bool is = true;
        for (int i = 0; i < 16; ++i) if (need[i] != -1) {
            is &= !((s >> i & 1) ^ need[i]);
        }
        if (is) {
            ans += dp[0][s];
            if (ans >= mod) ans -= mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}