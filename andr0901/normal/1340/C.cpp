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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> m >> n;
    vector <int> a(n);
    cin >> a;
    sort(all(a));
    int g, r;
    cin >> g >> r;
    const int INF = 1e9;
    vector <vector <int>> dp(n, vector <int> (g, INF));
    dp[0][0] = 0;
    deque <pii> q = {{0, 0}};
    int cnt = 0;
    while (!q.empty()) {
        auto [x, t] = q.front();
        q.pop_front();
        if (x + 1 < n) {
            int d = a[x + 1] - a[x];
            int e = d + t;
            if (e == g)
                e -= g;
            if (e < g) {
                if (t) {
                    if (dp[x][t] < dp[x + 1][e]) {
                        dp[x + 1][e] = dp[x][t];
                        q.eb(x + 1, e);
                    }
                } else {
                    if (dp[x][t] + 1 < dp[x + 1][e]) {
                        dp[x + 1][e] = dp[x][t] + 1;
                        q.eb(x + 1, e);
                    }
                }
            }
        }
        if (x - 1 >= 0) {
            int d = a[x] - a[x - 1];
            int e = d + t;
            if (e == g)
                e -= g;
            if (e < g) {
                if (t) {
                    if (dp[x][t] < dp[x - 1][e]) {
                        dp[x - 1][e] = dp[x][t];
                        q.eb(x - 1, e);
                    }
                } else {
                    if (dp[x][t] + 1 < dp[x - 1][e]) {
                        dp[x - 1][e] = dp[x][t] + 1;
                        q.eb(x - 1, e);
                    }
                }
            }
        }
        ++cnt;
        /*cout << x << " " << t << "\n";
        for (auto i : q)
            cout << i.fs << " " << i.sc << " " << dp[i.fs][i.sc] << "\n";
        cout << "\n";*/
        //return 0;
    }
    /*cout << cnt << "\n";
    forn (i, 0, n)
        cout << dp[i] << "\n";*/
    ll ans = 1e18;
    forn (i, 0, g) {
        if (!i && dp[n - 1][i] != INF)
            chkmin(ans, 1LL * (r + g) * (dp[n - 1][i] - 1) + g);
        if (i && dp[n - 1][i] != INF)
            chkmin(ans, 1LL * (r + g) * (dp[n - 1][i] - 1) + i);

        /*if (!i)
            cout << 1LL * (r + g) * (dp[n - 1][i] - 1) + g << "\n";
        else
            cout << 1LL * (r + g) * (dp[n - 1][i] - 1) + i << "\n";*/
    }
    if (ans == 1e18)
        cout << "-1";
    else
        cout << ans;
    return 0;
}