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
const int mod = 998244353, N = 2e5 + 7, logN = 18, C = 1;

vector <array <int, 3>> adj[N];
int in[N], out[N], _t;

struct Seg {
    int l, r, m, mn, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mn(0), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        mn = min(ch[0]->mn, ch[1]->mn);
    }
    void give(int x) {
        mn += x, lz += x;
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz), lz = 0;
    }
    void add(int a, int b, int v) { 
        if (a <= l && r <= b)
            give(v);
        else {
            push();
            if (a < m)
                ch[0]->add(a, b, v);
            if (m < b)
                ch[1]->add(a, b, v);
            pull();
        }
    }
};

vector <array <int, 3>> edge;
lli ans = 0;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

void dfs(int v, int pa, lli now = 1) {
    in[v] = _t++;
    ans += now;
    if (ans >= mod)
        ans -= mod;
    for (auto i : adj[v]) if (i[0] != pa) {
        edge.pb(i);
        dfs(i[0], v, now * modpow(i[1], mod - 2) % mod * i[2] % mod);
    }
    out[v] = _t++;
}

int lp[N], cc[N];

void build() {
    vector <int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            p.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; 1ll * p[j] * i < N; ++j) {
            lp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

int main () {
    owo;
    build();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0, u, v, x, y; i < n - 1; ++i) {
            cin >> u >> v >> x >> y, --u, --v;
            adj[u].pb({v, x, y}), adj[v].pb({u, y, x});
        }
        dfs(0, -1);
        vector <vector <int>> fac(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            vector <int> p;
            {
                int now = edge[i][1];
                while (now > 1) {
                    p.pb(lp[now]);
                    now /= lp[now];
                }
            }
            {
                int now = edge[i][2];
                while (now > 1) {
                    p.pb(lp[now]);
                    now /= lp[now];
                }
            }
            sort(all(p)), p.resize(unique(all(p)) - p.begin());
            for (int x : p)
                fac[x].pb(i);
        }
        Seg root(0, 2 * n);
        lli res = 1;
        for (int i = 2; i <= n; ++i) {
            for (int id : fac[i]) {
                int cnt = 0;
                {
                    int now = edge[id][1];
                    while (now % i == 0)
                        now /= i, cnt--;
                }
                {
                    int now = edge[id][2];
                    while (now % i == 0)
                        now /= i, cnt++;
                }
                cc[id] = cnt;
                root.add(in[edge[id][0]], out[edge[id][0]] + 1, cnt);
            }
            int mn = -root.mn;
            for (int _ = 0; _ < mn; ++_)
                res = res * i % mod;
            for (int id : fac[i]) {
                root.add(in[edge[id][0]], out[edge[id][0]] + 1, -cc[id]);
            }
        }
        cout << ans * res % mod << '\n';
        for (int i = 0; i < n; ++i)
            adj[i].clear();
        _t = 0;
        edge.clear();
        ans = 0;
    }
}