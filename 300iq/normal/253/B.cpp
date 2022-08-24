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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (auto &x : a) {
        scanf("%d", &x);
    }
    sort(all(a));
    int ans = n;
    for (int i = 0; i < n; i++) {
        int t = 2 * a[i];
        int it = upper_bound(all(a), t) - a.begin();
        ans = min(ans, i + n - it);
    }
    printf("%d\n", ans);
}