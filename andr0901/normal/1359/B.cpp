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
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    long long ans = 0;
    forn (i, 0, n) {
        string a;
        cin >> a;
        int covered = 0, uncovered = 1e9;
        forn (j, 0, m) {
            int new_covered = 1e9, new_uncovered = 1e9;
            if (a[j] == '.') {
                chkmin(new_covered, min(covered + x, uncovered + y));
                chkmin(new_uncovered, min(covered, uncovered + x));
            } else {
                new_covered = covered;
                new_uncovered = 1e9;
            }
            covered = new_covered;
            uncovered = new_uncovered;
            //cout << covered << " " << uncovered << "\n";
        }
        //out << "\n";
        ans += covered;
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