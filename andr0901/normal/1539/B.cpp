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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> pr(n + 1, vector<int> (26));
    forn (i, 0, n) {
        pr[i + 1] = pr[i];
        pr[i + 1][s[i] - 'a']++;
    }
    while (q --> 0) {
        int l, r;
        cin >> l >> r;
        --l;
        vector<int> segment = pr[r];
        forn (i, 0, 26) {
            segment[i] -= pr[l][i];
        }
        long long ans = 0;
        forn (i, 0, 26) {
            ans += 1LL * (i + 1) * segment[i];
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t --> 0)
        solve();
    return 0;
}