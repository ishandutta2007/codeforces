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

vector <int> a;
vector <vector <int>> dp;
// -1 - cant make equal
// 0 - not visited

int go(int l, int r) {
    if (dp[l][r] != 0)
        return dp[l][r];
    if (r - l == 0)
        return dp[l][r] = a[l];
    forn (i, l, r)
        if (go(l, i) != -1 && go(l, i) == go(i + 1, r))
            return dp[l][r] = go(l, i) + 1;
    return dp[l][r] = -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    cin >> a;
    dp.resize(n, vector <int> (n));
    go(0, n - 1);
   /* forn (i, 0, n)
        forn (j, i, n)
            cout << i << " " << j << ": " << dp[i][j] << "\n";*/
    vector <int> ans(n + 1, 1e9);
    forn (i, 0, n) {
        if (dp[0][i] != -1)
            ans[i] = 1;
        forn (j, 1, i + 1)
            if (dp[j][i] != -1)
                ans[i] = min(ans[i], ans[j - 1] + 1);
    }
    cout << ans[n - 1];
    return 0;
}