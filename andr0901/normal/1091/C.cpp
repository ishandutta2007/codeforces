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
#define int long long

typedef long long ll;

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    set <int> s;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 && n % (n / i) == 0) {
            int t = i;
            s.insert((2 + n - t) * (n / t) / 2);
            t = n / i;
            s.insert((2 + n - t) * (n / t) / 2);
        }
    }
    for (auto i : s)
        cout << i << " ";
    return 0;
}