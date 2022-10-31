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
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    int ans = 1e9, ansi;
    forn (i, 1, 200) {
        int s = 0;
        forn (j, 0, n)
            s += min({abs(a[j] - i), abs(a[j] - i - 1), abs(a[j] - i + 1)});
        if (s < ans) {
            ans = s;
            ansi = i;
        }
    }
    cout << ansi << " " << ans;
    return 0;
}