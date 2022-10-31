#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(k);
    forn (i, 0, n) {
        int t;
        cin >> t;
        a[t % k]++;
    }
    int ans = 0;
    forn (i, 1, (k + 1) / 2)
        ans += 2 * min(a[i], a[(k - i) % k]);
    ans += a[0] - a[0] % 2;
    if (k % 2 == 0)
        ans += a[k / 2] - a[k / 2] % 2;
    cout << ans;
    return 0;
}