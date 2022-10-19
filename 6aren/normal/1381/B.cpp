#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<int> to_solve;
    for (int &e : a) cin >> e;
    int mx = 0;
    int cnt = 0;
    for (int e : a) {
        if (e > mx) {
            mx = e;
            to_solve.pb(cnt);
            cnt = 1;
        } else cnt++;
    }
    to_solve.pb(cnt);
    vector<bool> dp(n + 1, 0);
    dp[0] = 1;
    for (int e : to_solve) {
        for (int i = n; i >= e; i--) dp[i] = (dp[i] | dp[i - e]);
    }
    cout << (dp[n] ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}