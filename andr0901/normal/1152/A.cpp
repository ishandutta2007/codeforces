#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    forn (i, 0, n) {
        int t;
        cin >> t;
        if (t % 2)
            a1++;
        else 
            a0++;
    }
    forn (i, 0, m) {
        int t;
        cin >> t;
        if (t % 2)
            b1++;
        else 
            b0++;
    }
    cout << min(a1, b0) + min(a0, b1);
    return 0;
}