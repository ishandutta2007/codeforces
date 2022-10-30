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
    int n;
    cin >> n;
    map<int, vector<vector<int>>> mp;
    vector<vector<int>> a;
    forn (i, 0, n) {
        int x, y;
        cin >> x >> y;
        mp[x].pb({x, y, i});
        mp[y].pb({y, x, i});
    }
    sort(all(a));
    vector<int> ans(n, -2);
    int mn_h = 1e9 + 5, mn_idx = -2;
    for (auto [tmp, a] : mp) {
        forn (i, 0, sz(a)) {
            if (ans[a[i][2]] == -2) {
                if (a[i][1] > mn_h)
                    ans[a[i][2]] = mn_idx;
            }
        }
        forn (i, 0, sz(a)) {
            if (a[i][1] < mn_h) {
                mn_h = a[i][1];
                mn_idx = a[i][2];
            }
        }
    }
    for (int x : ans)
        cout << x + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}