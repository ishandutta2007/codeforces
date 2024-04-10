#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll ans = 0;
    int n;
    cin >> n;
    forn (i, 0, n) {
        char c;
        cin >> c;
        if ((c - '0') % 2 == 0)
            ans += i + 1;
    }
    cout << ans;
    return 0;
}