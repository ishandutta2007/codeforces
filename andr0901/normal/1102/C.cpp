#pragma GCC optmize("Ofast")
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
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    if (x > y)
        return cout << n, 0;
    sort(all(a));
    forn (i, 0, n) {
        if (a[i] > x) {
            return cout << (i + 1) / 2, 0;
        }
    }
    cout << (n + 1) / 2;
    return 0;
}