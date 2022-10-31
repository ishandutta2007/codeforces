//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <vector <int>> gr, rev_gr;

constexpr int INF = 1e9;

int n;

int dijkstra_small() {
    int mn = INF;
    vector <int> dst(n, INF);
    dst[0] = 0;
    forn (p, 0, 22) {
        set <pii> s;
        forn (i, 0, n)
            s.emplace(dst[i], i);
        while (!s.empty()) {
            int v = s.begin() -> sc;
            s.erase(s.begin());
            if (p % 2 == 0) {
                for (int u : gr[v]) {
                    if (dst[v] + 1 < dst[u]) {
                        s.erase({dst[u], u});
                        dst[u] = dst[v] + 1;
                        s.emplace(dst[u], u);
                    }
                }
            } else {
                for (int u : rev_gr[v]) {
                    if (dst[v] + 1 < dst[u]) {
                        s.erase({dst[u], u});
                        dst[u] = dst[v] + 1;
                        s.emplace(dst[u], u);
                    }
                }
            }
        }
        chkmin(mn, dst[n - 1]);
        forn (i, 0, n)
            dst[i] += (1 << p);
        // cerr << dst << "\n";
    }
    return mn;
}

pii dijkstra_big() {
    vector <vector <pii>> dst(2, vector <pii> (n, {INF, INF}));
    dst[0][0] = {0, 0};
    set <pair <pii, pii>> s = {{dst[0][0], {0, 0}}};
    while (!s.empty()) {
        int parity = (*s.begin()).sc.fs, v = (*s.begin()).sc.sc;
        s.erase(s.begin());
        if (parity == 0) {
            for (int u : gr[v]) {
                if (make_pair(dst[0][v].fs, dst[0][v].sc + 1) < dst[0][u]) {
                    s.erase({dst[0][u], {0, u}});
                    dst[0][u] = {dst[0][v].fs, dst[0][v].sc + 1};
                    s.insert({dst[0][u], {0, u}});
                }
            }
            for (int u : rev_gr[v]) {
                if (make_pair(dst[0][v].fs + 1, dst[0][v].sc + 1) < dst[1][u]) {
                    s.erase({dst[1][u], {1, u}});
                    dst[1][u] = {dst[0][v].fs + 1, dst[0][v].sc + 1};
                    s.insert({dst[1][u], {1, u}});
                }
            }
            if (make_pair(dst[0][v].fs + 1, dst[0][v].sc) < dst[1][v]) {
                s.erase({dst[1][v], {1, v}});
                dst[1][v] = {dst[0][v].fs + 1, dst[0][v].sc};
                s.insert({dst[1][v], {1, v}});
            }
        } else {
            for (int u : rev_gr[v]) {
                if (make_pair(dst[1][v].fs, dst[1][v].sc + 1) < dst[1][u]) {
                    s.erase({dst[1][u], {1, u}});
                    dst[1][u] = {dst[1][v].fs, dst[1][v].sc + 1};
                    s.insert({dst[1][u], {1, u}});
                }
            }
            for (int u : gr[v]) {
                if (make_pair(dst[1][v].fs + 1, dst[1][v].sc + 1) < dst[0][u]) {
                    s.erase({dst[0][u], {0, u}});
                    dst[0][u] = {dst[1][v].fs + 1, dst[1][v].sc + 1};
                    s.insert({dst[0][u], {0, u}});
                }
            }
            if (make_pair(dst[1][v].fs + 1, dst[1][v].sc) < dst[0][v]) {
                s.erase({dst[0][v], {0, v}});
                dst[0][v] = {dst[1][v].fs + 1, dst[1][v].sc};
                s.insert({dst[0][v], {0, v}});
            }
        }
    }
    forn (i, 0, n)
        cerr << i << ": " << dst[0][i].fs << " " << dst[0][i].sc << "  " << dst[1][i].fs << " " << dst[1][i].sc << "\n";
    return min(dst[0][n - 1], dst[1][n - 1]);
}

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    int t = bin_pow(a, p / 2);
    return (1LL * t * t) % MOD;
}

int inv(int x) {
    return bin_pow(x, MOD - 2);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m;
    cin >> n >> m;
    gr.resize(n), rev_gr.resize(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), rev_gr[u].pb(v);
    }
    int ans_small = dijkstra_small();
    cerr << ans_small << "\n";
    auto ans_big = dijkstra_big();
    cerr << ans_big.fs << " " << ans_big.sc << "\n";
    if (ans_big.fs >= 25) {
        int ans = 0, p = 1;
        forn (i, 0, ans_big.fs) {
            ans = add(ans, p);
            p = mul(p, 2);
        }
        cout << add(ans, ans_big.sc);
    } else {
        cout << ans_small;
    }
    return 0;
}