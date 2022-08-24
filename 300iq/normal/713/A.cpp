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

int dp[(1 << 18) + 7];

int main() {
    //freopen("t.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1) {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) {
            char c;
            scanf(" %c", &c);
            ll x;
            scanf("%lld", &x);
            string s = "";
            int t = 0;
            while (x > 0) {
                s += (x % 2 + '0'), x /= 10;
            }
            reverse(all(s));
            for (auto c : s) {
                t = t * 2 + (c - '0');
            }
            if (c == '+') dp[t]++;
            else if (c == '-') dp[t]--;
            else printf("%d\n", dp[t]);
        }
        //puts("NEW TEST");
    }
}