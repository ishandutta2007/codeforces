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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = 0, sum = 0;
    vector <int> c(n);
    vector <int> off(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        sum += c[i];
        ans += (c[i] * (ll) (c[(i + 1) % n]));
    }
    ll p = 0;
    int u;
    for (int i = 0; i < k; i++) {
        scanf("%d", &u);
        --u;
        p += (sum - !off[(u + 1) % n] * c[(u + 1) % n] - !off[(u - 1 + n) % n] * c[(u - 1 + n) % n] - c[u]) * (ll) c[u];
        off[u] = 1;
        sum -= c[u];
    }
    ans += p;
    printf("%lld\n", ans);
}