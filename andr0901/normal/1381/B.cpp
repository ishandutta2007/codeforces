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
    n *= 2;
    vector <int> a(n);
    forn (i, 0, n) {
        cin >> a[i];
        a[i]--;
    }
    vector <int> t;
    for (int i = n - 1; i >= 0; ) {
        int mx = -1, mx_idx;
        forn (j, 0, i + 1) {
            if (a[j] > mx) {
                mx = a[j];
                mx_idx = j;
            }
        }
        //cerr << mx << " " << mx_idx << " " << i << "\n";
        t.pb(i - mx_idx + 1);
        i = mx_idx - 1;
    }
    cerr << t << "\n";
    n /= 2;
    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int x : t) {
        vector <int> n_dp = dp;
        forn (i, 0, n + 1)
            if (i + x <= n)
                n_dp[i + x] |= dp[i];
        dp = n_dp;
        cerr << dp << "\n";
    }
    if (dp[n])
        cout << "YES";
    else
        cout << "NO";
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