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
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    forn (i, 0, n)
        forn (j, 0, m) 
            cin >> a[i][j];
    int ans = 0;
    forn (i, 1, n - 1) {
        forn (j, 1, m - 1) {
            if ((a[i][j] == '*' && 
                    a[i][j + 1] == '*' && 
                    a[i][j - 1] == '*' && 
                    a[i - 1][j] == '*' && 
                    a[i + 1][j] == '*')) {
                for (int k = i + 1; k < n; k++) {
                    if (a[k][j] == '.') {
                        break;
                    } else {
                        a[k][j] = '.';
                    }
                }
                for (int k = i - 1; k >= 0; k--) {
                    if (a[k][j] == '.') {
                        break;
                    } else {
                        a[k][j] = '.';
                    }
                }
                for (int k = j + 1; k < m; k++) {
                    if (a[i][k] == '.') {
                        break;
                    } else {
                        a[i][k] = '.';
                    }
                }
                for (int k = j - 1; k >= 0; k--) {
                    if (a[i][k] == '.') {
                        break;
                    } else {
                        a[i][k] = '.';
                    }
                }
                a[i][j] = '.';
                forn (k, 0, n) 
                    forn (l, 0, m)
                         if (a[k][l] == '*')
                            return cout << "NO", 0;
                return cout << "YES", 0;
            }
        }
    }
    cout << "NO";
    return 0;
}