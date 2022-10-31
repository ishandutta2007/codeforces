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
    map <int, vector <int>> mp;
    forn (i, 0, n) {
        int x;
        cin >> x;
        mp[x].pb(i);
    }
    if (mp.size() == 1) {
        cout << "0\n";
        return;
    }
    int ans = 1e9;
    for (auto& [val, idxs] : mp) {
        if (idxs.size() == 1) {
            if (idxs[0] == 0 || idxs[0] == n - 1)
                chkmin(ans, 1);
            else
                chkmin(ans, 2);
            continue;
        }
        int cnt = 0;
        forn (i, 1, sz(idxs))
            if (idxs[i] - idxs[i - 1] > 1)
                ++cnt;
        if (idxs[0] != 0)
            ++cnt;
        if (idxs.back() != n - 1)
            ++cnt;
        chkmin(ans, cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}