#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const ll INF = (ll) 1e18 + 7;
const int MAXN = (int) 1e5 + 7;

ll dp[MAXN][2];
int v[MAXN];
char c[MAXN];
string s[MAXN];
string rs[MAXN];

string next() {
    scanf(" %s", c);
    return string(c);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; i++) {
        s[i] = next();
        rs[i] = string(s[i].rbegin(), s[i].rend());
    }
    dp[0][0] = 0;
    dp[0][1] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i][1] = INF;
        if (s[i] >= s[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (s[i] >= rs[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (rs[i] >= s[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + v[i]);
        } 
        if (rs[i] >= rs[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + v[i]);
        }
    }
    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    printf("%lld\n", (ans == INF ? -1 : ans));
}