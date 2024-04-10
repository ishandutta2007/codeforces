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

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> a(n);
    cin >> a;
    map <int, int> m;
    forn (i, 0, n)
        m[a[i]]++;
    int left;
    forn (i, 1, n + 2)
        if (m.find(i) == m.end())
            left = i;
    set <pii> s;
    for (auto i : m)
        s.emplace(i.sc, i.fs);
    vector <vector <int>> ans(n + 2);
    forn (i, 0, x) {
        auto [cnt, col] = *--s.end();
        s.erase(--s.end());
        --cnt;
        if (cnt > 0)
            s.emplace(cnt, col);
        ans[col].pb(col);
        cerr << col << " ";
    }
    cerr << "\n";
    vector <int> rest;
    for (auto [cnt, col] : s)
        forn (i, 0, cnt)
            rest.pb(col);
    vector <int> shifted;
    forn (i, 0, sz(rest))
        shifted.pb(rest[(i + sz(rest) / 2) % sz(rest)]);
    int good = 0;
    forn (i, 0, sz(rest))
        if (rest[i] != shifted[i])
            ++good;
    if (good < y - x) {
        cout << "NO\n";
        return;
    }
    cerr << rest << "\n" << shifted << "\n";
    int t = y - x;
    forn (i, 0, sz(rest))
        if (rest[i] != shifted[i] && t) {
            ans[rest[i]].pb(shifted[i]);
            --t;
        }
    cout << "YES\n";
    for (int x : a) {
        if (ans[x].empty()) {
            cout << left;
        } else {
            cout << ans[x].back();
            ans[x].pop_back();
        }
        cout << " ";
    }
    cout << "\n";
    cerr << "---\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}