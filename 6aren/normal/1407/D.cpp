#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> dp(n, 1e9);
    dp[n - 1] = 0;
    vector<ii> inc;
    vector<ii> dec;
    inc.pb({a[n - 1], n - 1});
    dec.pb({a[n - 1], n - 1});
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            dp[i] = dp[i + 1] + 1;
        } else if (a[i] > a[i + 1]) {
            do {
                ii u = inc.back();
                dp[i] = min(dp[i], dp[u.y] + 1);
                if (u.x >= a[i]) {
                    break;
                }
                inc.pop_back();
            } while (!inc.empty());
        } else if (a[i] < a[i + 1]) {
            do {
                ii u = dec.back();
                dp[i] = min(dp[i], dp[u.y] + 1);
                if (u.x <= a[i]) {
                    break;
                }
                dec.pop_back();
            } while (!dec.empty());
        }
        while (!inc.empty() && inc.back().x <= a[i]) inc.pop_back();
        while (!dec.empty() && dec.back().x >= a[i]) dec.pop_back();
        inc.pb({a[i], i});
        dec.pb({a[i], i});
    }
    cout << dp[0];
    return 0;
}