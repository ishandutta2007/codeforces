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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    forn (i, 0, n)
        s[i] -= 'a';
    vector <vector <int>> a(k, vector <int> (26));
    for (int i = 0; i < n; i += k)
        forn (j, 0, k)
            a[j][s[i + j]]++;
    int ans = 0;
    forn (i, 0, k / 2) {
        //cout << i << " " << k - i - 1 << "\n";
        int popular = 0;
        forn (j, 0, 26)
            chkmax(popular, a[i][j] + a[k - i - 1][j]);
        //cout << popular << "  ";
        ans += 2 * (n / k) - popular;
    }
    if (k % 2) {
        int popular = 0;
        forn (j, 0, 26)
            chkmax(popular, a[k / 2][j]);
        ans += n / k - popular;
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