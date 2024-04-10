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

constexpr long long INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pii> a(n);
    long long ans = 0;
    forn (i, 0, n) {
        cin >> a[i].fs >> a[i].sc;
        ans += a[i].sc;
    }
    sort(all(a));
    vector<long long> dst(n, INF);
    dst[0] = 0;
    set<pair<long long, int>> s = {{0, 0}};
    while (!s.empty()) {
        auto [d, i] = *s.begin();
        s.erase(s.begin());
        vector<int> edges;
        if (i != 0) {
            edges.pb(i - 1);
        }
        int j = lower_bound(all(a), make_pair(a[i].fs + a[i].sc + 1, -1LL)) - a.begin();
        cerr << i << " " << j << "\n";
        if (j != 0) {
            edges.pb(j - 1);
        }
        if (j != n) {
            edges.pb(j);
        }
        for (int j : edges) {
            long long new_d = d + max(0LL, -a[i].fs + a[j].fs - a[i].sc);
            if (new_d < dst[j]) {
                s.erase({dst[j], j});
                dst[j] = new_d;
                s.insert({dst[j], j});
            }
        }
    }
    cerr << dst << "\n";
    cout << ans + dst[n - 1];
    return 0;
}