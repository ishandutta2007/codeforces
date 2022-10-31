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

vector <vector <int>> gr, dp;

vector <int> par;

const int INF = 1e9;

void dfs(int v, int p = -1) {
    int mx = 0;
    for (int u : gr[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        dp[v][0] += max(dp[u][0], dp[u][1]);
        dp[v][1] += max(dp[u][0], dp[u][1]);
        if (1 + dp[u][0] - max(dp[u][0], dp[u][1]) >= mx) {
            chkmax(mx, 1 + dp[u][0] - max(dp[u][0], dp[u][1]));
            par[v] = u;
        }
    }
    dp[v][1] += mx;
    cerr << v << " " << dp[v][0] << " " << dp[v][1] << "\n";
}

vector <int> ans;

void restore(int v, int p = -1) {
    if (dp[v][1] > dp[v][0]) {
        ans[v] = par[v];
        ans[ans[v]] = v;
    }
    for (int u : gr[v])
        if (u != p)
            restore(u, v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    dp.resize(n, vector <int> (2));
    par.resize(n, -1), ans.resize(n, -1);
    dfs(0);
    restore(0);
    long long sum = 0;
    sum += 2 * max(dp[0][0], dp[0][1]);
    cerr << ans << "\n";
    forn (i, 0, n) {
        if (ans[i] != -1)
            continue;
        for (int j : gr[i]) {
            if (ans[j] != -1) {
                int t = ans[j];
                ans[j] = i;
                ans[i] = t;
                sum += 2;
                break;
            }
        }
    }
    cout << sum << "\n";
    for (int x : ans)
        cout << x + 1 << " ";
    return 0;
}