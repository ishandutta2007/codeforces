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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> ans(n);
    forn (i, 0, n) {
        vector <vector <int>> dp(n, vector <int> (m));
        vector <vector <int>> pref(n + 1, vector <int> (m));
        dp[i][0] = 1;
        forn (j, 0, n)
            pref[j + 1][0] = add(pref[j][0], dp[j][0]); 
        forn (j, 1, m) {
            forn (k, 0, n)
                dp[k][j] = pref[k + 1][j - 1];
            forn (k, 0, n)
                pref[k + 1][j] = add(pref[k][j], dp[k][j]);
        }
        /*if (i == 0) {
            forn (j, 0, n)
                forn (k, 0, m)
                    cout << dp[j][k] << " \n"[k == m - 1];
            cout << "\n---\n";
            forn (j, 0, n + 1)
                forn (k, 0, m)
                    cout << pref[j][k] << " \n"[k == m - 1];
        }*/
        forn (j, 0, n)
            ans[i] = add(ans[i], dp[j][m - 1]);
    }
    /*forn (i, 0, n)
        cout << ans[i] << "\n";*/
    int ANS = 0;
    forn (i, 0, n) {
        int down = 0;
        int idx = n - 1;
        forn (j, 0, i + 1) {
            down = add(down, ans[idx--]);
        }
        ANS = add(ANS, mul(down, ans[i]));
    }
    cout << ANS;
    return 0;
}