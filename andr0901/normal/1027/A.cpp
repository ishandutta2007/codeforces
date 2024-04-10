#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        string s;
        cin >> n >> s;
        bool ok = 1;
        forn (i, 0, n / 2)
            if (abs(s[i] - s[n - i - 1]) > 2 || abs(s[i] - s[n - i - 1]) % 2)
                ok = 0;
        if (ok)
            cout << "YES";
        else 
            cout << "NO";
        cout << "\n";
    }
    return 0;
}