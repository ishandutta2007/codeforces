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

vector <vector <pii>> a;
vector <vector <int>> dp;

int m;

int solve(int l, int r) {
    if (r < 0 || l >= m)
        return 0;
   // cerr << l << " " << r << "\n";
    if (l > r)
        return dp[l][r] = 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = 0;
    forn (m, l, r + 1) {
        int cnt = 0;
        for (auto [L, R] : a[m])
            if (l <= L && R <= r)
                ++cnt;
        chkmax(dp[l][r], solve(l, m - 1) + cnt * cnt + solve(m + 1, r));
    }
    cerr << l << " " << r << " " << dp[l][r] << "\n";
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> m;
    a.resize(m);
    forn (i, 0, n) {
        int k;
        cin >> k;
        forn (j, 0, k) {
            int l, r;
            cin >> l >> r, --l, --r;
            forn (t, l, r + 1)
                a[t].pb({l, r});
        }
    }
    dp.resize(m, vector <int> (m, -1));
    cout << solve(0, m - 1);
    return 0;
}