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

vector <vector <int>> gr;
vector <int> sz;

int dfs(int v, int p = -1) {
    sz[v] = 1;
    for (int u : gr[v])
        if (u != p)
            sz[v] += dfs(u, v);
    return sz[v];
}

const int MOD = 1e9 + 7;

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


void solve() {
    int n;
    cin >> n;
    gr = vector <vector <int>> (n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    sz = vector <int> (n);
    dfs(0, -1);
    vector <long long> contribution;
    forn (i, 1, n)
        contribution.pb(1LL * sz[i] * (n - sz[i]));
    sort(all(contribution));

    int m;
    cin >> m;
    vector <int> p(m);
    cin >> p;
    sort(all(p));

    int edges = n - 1;
    int ans = 0;

    int prod = p.back();
    p.pop_back();
    if (m > edges) {
        forn (i, 0, m - edges) {
            prod = mul(prod, p.back());
            p.pop_back();
        }
    }
    ans = mul(contribution.back() % MOD, prod);
    contribution.pop_back();
    cerr << ans << "\n";
    forn (i, 1, edges) {
        if (p.empty()) {
            ans = add(ans,
                  mul(contribution.back() % MOD, 1));
        } else {
            ans = add(ans,
                      mul(contribution.back() % MOD, p.back()));
            p.pop_back();
        }
        contribution.pop_back();
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}