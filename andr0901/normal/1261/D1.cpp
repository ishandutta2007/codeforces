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

const int MOD = 998244353;

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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    a.pb(a[0]);
    vector <vector <int>> b(n, vector <int> (3));
    forn (i, 0, n) {
        if (a[i] == a[i + 1])
            b[i][1] = k;
        else {
            b[i][0] = b[i][2] = 1;
            b[i][1] = k - 2;
        }
    }
    unordered_map <int, int> dp;
    dp[0] = 1;
    forn (i, 0, n) {
        unordered_map <int, int> new_dp;
        forn (j, 0, 3) {
            for (auto k : dp) {
                new_dp[k.fs + j - 1] = add(new_dp[k.fs + j - 1], 
                                        mul(k.sc, b[i][j]));
            }
        }
        dp = new_dp;
    }
    int ans = 0;
    for (auto i : dp)
        if (i.fs > 0)
            ans = add(ans, i.sc);
    cout << ans;
    return 0;
}