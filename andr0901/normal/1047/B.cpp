#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll ans = INT_MIN;
    forn (i, 0, n) {
        ll a, b;
        cin >> a >> b;
        ans = max(ans, a + b);
    }
    cout << ans;
    return 0;
}