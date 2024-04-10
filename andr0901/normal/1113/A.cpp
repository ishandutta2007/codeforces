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
#define int long long

typedef long long ll;

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, v;
    cin >> n >> v;
    ll ans = 0;
    int cur = 0, sum = 0;
    forn (i, 1, n + 1) {
        while (cur < v) {
            if (sum == n - 1)
                break;
            ans += i;
            cur++;
            sum++;
        }
        cur--;
    }
    cout << ans;
    return 0;
}