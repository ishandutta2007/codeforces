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

vector <int> a;
int n, m, k;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    a.resize(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <int> b;
    forn (i, 1, n)
        b.pb(a[i] - a[i - 1] - 1);
    sort(all(b));
    reverse(all(b));
    int ans = a[n - 1] - a[0] + 1;
    forn (i, 0, k - 1)
        ans -= b[i];
    cout << ans;
    return 0;
}