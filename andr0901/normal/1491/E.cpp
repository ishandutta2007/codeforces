#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
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

constexpr int N = 2e5 + 8;

vector<int> f;

vector<int> gr[N];
int sz[N];
pii q[N];

int SZ;
int needed;

void dfs(int v, vector<pii>& candidates) {
    q[0] = {v, -1};
    int lst = 0, len = 1;
    while (lst < len) {
        auto [v, p] = q[lst++];
        sz[v] = 0;
        for (int u : gr[v]) {
            if (u != p) {
                q[len++] = {u, v};
            }
        }
    }
    for (int i = len - 1; i >= 0; --i) {
        auto [v, p] = q[i];
        sz[v]++;
        if (p != -1)
            sz[p] += sz[v];
        if (sz[v] == needed) {
            candidates.eb(v, p);
        }
        if (SZ - sz[v] == needed) {
            candidates.eb(p, v);
        }
    }
}

mt19937 rng(time(0));

int solve(int t, int lvl) {
    if (lvl <= 3) {
        return true;
    }
    SZ = f[lvl];
    needed = f[lvl - 1];
    vector<pii> candidates;
    // cerr <<  "\n" << t <<  " " << lvl << " " << N << " " << needed << "\n";
    // forn (i, 0, sz(gr))
    //     cerr << gr[i].size() << " ";
    // cerr << "\n";
    dfs(t, candidates);
    shuffle(all(candidates), rng);
    int ans = false;
    for (auto [v, u] : candidates) {
        forn (i, 0, sz(gr[v])) {
            if (gr[v][i] == u) {
                swap(gr[v][i], gr[v].back());
                gr[v].pop_back();
                break;
            }
        }
        forn (i, 0, sz(gr[u])) {
            if (gr[u][i] == v) {
                swap(gr[u][i], gr[u].back());
                gr[u].pop_back();
                break;
            }
        }
        ans |= (solve(u, lvl - 2) && solve(v, lvl - 1));
        if (ans)
            return ans;
        gr[v].pb(u);
        gr[u].pb(v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    f.pb(1), f.pb(1);
    while (f.back() <= 1e6) {
        f.pb(f[sz(f) - 1] + f[sz(f) - 2]);
    }
    int n;
    cin >> n;
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    int t = -1;
    forn (i, 0, sz(f))
        if (f[i] == n)
            t = i;
    if (t == -1) {
        cout << "NO\n";
        return 0;
    }
    cerr << t << "\n";
    cout << (solve(0, t) ? "YES" : "NO") << "\n";
    return 0;
}