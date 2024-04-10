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

constexpr int INF = 1e9;

int SOLVE(vector<vector<int>> c, int m) {
    vector<int> t;
    for (int i = sz(c[0]) - 1; i - 1 >= 0; i -= 2) {
        t.pb(c[0][i] + c[0][i - 1]);
    }
    forn (i, 0, sz(c[1]))
        t.pb(c[1][i]);
    sort(rall(t));
    int freed = 0;
    int ans = 0;
    if (freed >= m) {
        return ans;
    }
    forn (i, 0, sz(t)) {
        ans += 2;
        freed += t[i];
        if (freed >= m) {
            return ans;
        }
    }
    return INF;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    cin >> a >> b;
    vector<vector<int>> c(2);
    forn (i, 0, n)
        c[b[i] - 1].pb(a[i]);
    forn (i, 0, 2)
        sort(all(c[i]));
    int ans = SOLVE(c, m);
    if (!c[0].empty()) {
        m -= c[0].back();
        c[0].pop_back();
        chkmin(ans, 1 + SOLVE(c, m));
    }
    cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}