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

vector <vector <int>> gr;

vector <int> h;

void dfs(int v, int p = -1, int cur_h = 0) {
    h[v] = cur_h;
    for (int u : gr[v])
        if (u != p)
            dfs(u, v, cur_h + 1);
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
    h.resize(n);
    dfs(0);
    vector <bool> parity(2);
    forn (i, 0, n)
        if (sz(gr[i]) == 1)
            parity[h[i] % 2] = true;
    if (parity[0] && parity[1])
        cout << "3 ";
    else
        cout << "1 ";

    vector <int> cnt(n);
    forn (i, 0, n)
        if (sz(gr[i]) == 1)
            cnt[gr[i][0]]++;

    int ans = n - 1;
    forn (i, 0, n)
        ans -= max(0, cnt[i] - 1);
    cout << ans;
    return 0;
}