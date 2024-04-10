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

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    forn (i, 1, n + 1) {
        cin >> a[i];
        a[i] -= 1;
    }
    int k = 26;
    vector <vector <int>> suf(n + 2, vector <int> (k));
    auto pref = suf;
    forn (i, 1, n + 1)
        forn (j, 0, k)
            pref[i][j] = pref[i - 1][j] + (a[i] == j);
    for (int i = n; i >= 1; --i)
        forn (j, 0, k)
            suf[i][j] = suf[i + 1][j] + (a[i] == j);
    int ans = 0;
    forn (i, 1, n + 1) {
        forn (j, i - 1, n + 1) {
            vector <int> cnt(k);
            forn (l, i, j + 1)
                cnt[a[l]]++;
            int mx = 0;
            forn (l, 0, k)
                chkmax(mx, 2 * min(pref[i - 1][l], suf[j + 1][l]));
            chkmax(ans, mx + *max_element(all(cnt)));
        }
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