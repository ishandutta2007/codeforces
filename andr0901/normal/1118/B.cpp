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
    int n;
    cin >> n;
    vector <int> a(n + 1);
    int x, y;
    x = y = 0;
    forn (i, 1, n + 1) {
        cin >> a[i];
        if (i % 2)
            y += a[i];
        else
            x += a[i];
    }
    int ans = 0;
    forn (i, 1, n + 1) {
        if (i % 2 == 0) {
            x -= a[i];
            x += a[i - 1];
        } else {
            y -= a[i];
            y += a[i - 1];
        }
        if (x == y)
            ans++;
    }
    cout << ans;
    return 0;
}