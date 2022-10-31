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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    /*int i = 1;
    while (1) {
        if ((i / k) * (i % k) == n) {
            cout << i;
            return 0;
        }
        i++;
    }*/
    int ans = INT_MAX;
    forn (i, 1, k) {
        if (n % i == 0) {
            ans = min(ans, k * n / i + i);
        }
    }
    cout << ans;
    return 0;
}