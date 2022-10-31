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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a != d)
        return cout << 0, 0;
    if (c) {
        if (a >= 1)
            cout << 1;
        else
            cout << 0;
    } else
        cout << 1;
    return 0;
}