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
    int n;
    cin >> n;
    vector <int> a(n);
    vector <vector <int>> b(n + 1);
    forn (i, 0, n) {
        cin >> a[i];
        b[n - a[i]].pb(i);
    }
    vector <int> ans(n);
    int col = 0;
    forn (i, 0, n + 1) {
        if (b[i].empty())
            continue;
        if (sz(b[i]) % i)
            return cout << "Impossible", 0;
        while (sz(b[i])) {
            col++;
            forn (j, 0, i) {
                ans[b[i].back()] = col;
                b[i].pop_back();
            }
        }
    }
    cout << "Possible\n";
    forn (i, 0, n) 
        cout << ans[i] << " ";
    return 0;
}