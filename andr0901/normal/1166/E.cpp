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
    int m, n;
    cin >> m >> n;
    vector <vector <bool>> q(m, vector <bool> (n));
    forn (i, 0, m) {
        int k;
        cin >> k;
        forn (j, 0, k) {
            int t;
            cin >> t;
            t--;
            q[i][t] = 1;
        }
    }
    forn (i, 0, m) {
        forn (j, i + 1, m) {
            vector <bool> used(n);
            forn (k, 0, n)
                if (q[i][k])
                    used[k] = 1;
            forn (k, 0, n) 
                if (q[j][k])
                    used[k] = 1;
            vector <int> c(n);
            bool ok = 0;
            forn (k, 0, n) 
                if (used[k] && (q[i][k] ^ q[j][k] == 0))
                    ok = 1;
            if (!ok)
                return cout << "impossible", 0;
        }
    }
    cout << "possible";
    return 0;
}