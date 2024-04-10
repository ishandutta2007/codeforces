#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <int> a;
vector <vector <int>> gr;
vector <int> dp;

int dfs(int v, int par = -1) {
    dp[v] = a[v];
    for (int u : gr[v])
        if (u != par)
            dp[v] += max(0, dfs(u, v));
    return dp[v];
}

vector <int> ans;

void dfs2(int v, int par = -1) {
    ans[v] = dp[v];
    for (int u : gr[v]) {
        if (u != par) {
            dp[v] -= max(0, dp[u]);
            dp[u] += max(0, dp[v]);
            dfs2(u, v);
            dp[u] -= max(0, dp[v]);
            dp[v] += max(0, dp[u]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    cin >> a;
    forn (i, 0, n)
        if (!a[i])
            a[i] = -1;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    dp.resize(n);
    dfs(0);
    ans.resize(n);
    dfs2(0);
    cout << ans;
    return 0;
}