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
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> b(n);
    forn (i, 0, n)
        cin >> b[i].fs;
    forn (i, 0, n)
        cin >> b[i].sc;
    map <pii, int> a;
    int t = 0;
    forn (i, 0, n) {
        if (b[i].fs == 0 && b[i].sc == 0) {
            t++;
            continue;
        }
        if (b[i].fs == 0 && b[i].sc != 0)
            continue;
        int t = gcd(b[i].fs, b[i].sc);
        a[{b[i].fs / t, b[i].sc / t}]++;
    }
    int ans = 0;
    for (auto i : a)
        ans = max(ans, i.sc);
    cout << ans + t;
    return 0;
}