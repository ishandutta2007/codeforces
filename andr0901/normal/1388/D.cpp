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

#define int long long

vector <int> a, gr, used, ord;
vector <vector <int>> inv;

void dfs(int v) {
    cerr << v << " ";
    if (v == -2 || used[v])
        return;
    for (int u : inv[v])
        dfs(u);
    used[v] = 1;
    ord.pb(v);
}

void solve() {
    int n;
    cin >> n;
    a = gr = used = vector <int> (n);
    cin >> a >> gr;
    inv = vector <vector <int>> (n);
    forn (i, 0, n) {
        gr[i]--;
        if (gr[i] != -2)
            inv[gr[i]].pb(i);
    }
    ord.clear();
    forn (i, 0, n)
        if (!used[i])
            dfs(i);
    used = vector <int> (n);
    int ans = 0;
    vector <int> real_ans;
    for (int i : ord) {
        if (a[i] < 0)
            continue;
        used[i] = true;
        real_ans.pb(i + 1);
        ans += a[i];
        if (gr[i] != -2)
            a[gr[i]] += a[i];
    }
    reverse(all(ord));
    for (int i : ord) {
        if (used[i])
            continue;
        used[i] = true;
        real_ans.pb(i + 1);
        ans += a[i];
        if (gr[i] != -2)
            a[gr[i]] += a[i];
    }
    cout << ans << "\n" << real_ans << "\n";
}

 main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t --> 0)
        solve();
    return 0;
}