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
    int q;
    cin >> q;
    while (q --> 0) {
        ll n, a, b;
        cin >> n >> a >> b;
        if (n % 2)
            cout << min({a * n, n / 2 * b + a}) << "\n";
        else
            cout << min({a * n, n / 2 * b}) << "\n";
    }
    return 0;
}