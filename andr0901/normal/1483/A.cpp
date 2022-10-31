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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> days(m);
    vector<vector<int>> friends(n);
    vector<int> cnt(n);
    forn (i, 0, m) {
        int k;
        cin >> k;
        days[i].resize(k);
        forn (j, 0, k) {
            cin >> days[i][j];
            --days[i][j];
            friends[days[i][j]].pb(i);
            cnt[days[i][j]]++;
        }
    }
    int mx = max_element(all(cnt)) - cnt.begin();
    if (cnt[mx] < (m + 1) / 2) {
        cout << "YES\n";
        forn (i, 0, m) {
            cout << days[i][0] + 1 << " ";
        }
        return;
    }
    vector<int> ans(m);
    forn (i, 0, m) {
        bool found = false;
        for (int j : days[i])
            if (j == mx)
                found = true;
        if (!found) {
            ans[i] = days[i][0];
            continue;
        }
        ans[i] = mx;
        if (cnt[mx] == (m + 1) / 2) {
            continue;
        }
        for (int j : days[i]) {
            if (j != mx) {
                ans[i] = j;
                cnt[mx]--;
                break;
            }
        }
    }
    if (cnt[mx] > (m + 1) / 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
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