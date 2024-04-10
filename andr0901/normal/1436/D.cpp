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
vector <int> a;
vector <__int128_t> dp;

bool ok;

// void dfs(int v, __int128_t m) {
//     dp[v] = -a[v];
//     for (int u : gr[v]) {
//         dfs(u, m);
//         dp[v] += dp[u];
//     }
//     if (gr[v].size() == 0)
//         dp[v] += m;
//     if (dp[v] < 0)
//         ok = false;
// }

void dfs(__int128_t m) {
    for (int v = sz(gr) - 1; v >= 0; --v) {
        dp[v] = -a[v];
        if (gr[v].empty())
            dp[v] += m;
        for (int u : gr[v])
            dp[v] += dp[u];
        if (dp[v] < 0)
            ok = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int p;
        cin >> p, --p;
        gr[p].pb(i);
    }
    a.resize(n);
    cin >> a;
    int64_t l = -1, r = 1e18 + 5;
    while (r - l > 1) {
        dp = vector <__int128_t> (n);
        int64_t m = (l + r) / 2;
        ok = true;
        dfs(m);   
        if (ok)
            r = m;
        else
            l = m;
    }
    cout << r;
    return 0;
}