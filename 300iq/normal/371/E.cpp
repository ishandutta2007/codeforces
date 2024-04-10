#include <bits/stdc++.h>
#define int long long

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

const int MAXN = (int) 3e5 + 7;
ll dp[MAXN];

ll get(int l, int r) {
    return dp[r] - (l ? dp[l - 1] : 0);
}

main() {
    int n;
    scanf("%lld", &n);
    vector <pair <int, int> > b;
    vector <int> a(n);
    for (auto &x : a) {
        scanf("%lld", &x);
    }
    for (int i = 0; i < n; i++) {
        b.pb({a[i], i});
    }
    sort(all(b));
    sort(all(a));
    for (int i = 0; i < n; i++) {
        dp[i] = (i ? dp[i - 1] : 0ll) + a[i];
    }
    int k;
    scanf("%lld", &k);
    int i = 0;
    ll ans = LLONG_MAX;
    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum += i * (ll) a[i] - get(0, i - 1);
    }
    ans = sum;
    sum -= get(1, k - 1) - (k - 1) * a[0];
    for (int l = 1; l + k - 1 < n; l++) {
        int r = l + k - 1;
        sum += (k - 1) * (ll) a[r] - get(l, r - 1);
        if (sum < ans) {
            ans = sum;
            i = l;
        }
        sum -= get(l + 1, r) - (k - 1) * a[l];
    }
    for (int f = i; f <= i + k - 1; f++) {
        printf("%lld ", b[f].sc + 1);
    }
    puts("");
}