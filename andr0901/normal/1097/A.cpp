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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    forn (i, 0, 5) {
        string t;
        cin >> t;
        if (t[0] == s[0] || t[1] == s[1])
            return cout << "YES", 0;
    }
    cout << "NO";
    return 0;
}