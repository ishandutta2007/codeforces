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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0, cur = 0;
    while (10 * cur + 9 <= n) {
        cur = 10 * cur + 9;
        ans += 9;
    }
    n -= cur;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    cout << ans;
    return 0;
}