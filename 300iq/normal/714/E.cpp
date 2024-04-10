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

int n;
vector <int> a;
ll dp[2][100000 + 7];
ll pref[2][100000 + 7];
ll kek[2][1000000 + 7];
ll pkek[2][100000 + 7];


int main() {
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    vector <int> b(n);
    for (int i = 0; i < n; i++) b[i] = a[i];
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    int m = b.size();
    for (int i = 0; i < n; i++) {
        int cur = i % 2;
        for (int j = 0; j < m; j++) {
            dp[cur][j] = (i > 0 ? pref[cur ^ 1][j] : 0) + abs(a[i] - b[j]);
            pref[cur][j] = min((j > 0 ? pref[cur][j - 1] : LLONG_MAX), dp[cur][j]);
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        ans = min(ans, dp[(n - 1) % 2][i]);
    }
    printf("%lld\n", ans);
}