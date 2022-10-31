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

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pii> a(m);
    forn (i, 0, m)
        cin >> a[i].fs >> a[i].sc;
    sort(all(a));
    vector <int> suf(m + 1);
    for (int i = m - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + a[i].fs;
    vector <int> a_copy;
    forn (i, 0, m)
        a_copy.pb(a[i].fs);
    int ans = 0;
    forn (i, 0, m) {
        int j = lower_bound(all(a_copy), a[i].sc) - a_copy.begin();
        int left = n - 1;
        if (m - j > left)
            j = m - left;
        int cur = suf[j];
        int free = n - (m - j);
        if (i < j) {
            cur += a[i].fs;
            free--;
        }
        chkmax(ans, cur + free * a[i].sc);
    }
    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}