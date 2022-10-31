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
    int n;
    cin >> n;
    vector <int> a(1001);
    forn (i, 0, n * n) {
        int t;
        cin >> t;
        a[t]++;
    }
    vector <vector <int>> ans(n, vector <int> (n));
    forn (i, 0, n / 2) {
        forn (j, 0, n / 2) {
            forn (k, 0, 1001) {
                if (a[k] > 3) {
                    ans[i][j] = ans[n - 1 - i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = k;
                    a[k] -= 4;
                    break;
                }
            }
        }
    }
    if (n % 2) {
        forn (i, 0, n / 2) {
            forn (k, 0, 1001) {
                if (a[k] > 1) {
                    ans[i][n / 2] = ans[n - 1 - i][n / 2] = k;
                    a[k] -= 2;
                    break;
                }
            }
        }
        forn (j, 0, n / 2) {
            forn (k, 0, 1001) {
                if (a[k] > 1) {
                    ans[n / 2][j] = ans[n / 2][n - 1 - j] = k;
                    a[k] -= 2;
                    break;
                }
            }
        }
        forn (k, 0, 1001) {
            if (a[k] > 0) {
                ans[n / 2][n / 2] = k;
                a[k] -= 1;
                break;
            }
        }
    }
    /*forn (i, 0, n) {
        forn (j, 0, n)
            cout << ans[i][j] << " ";
        cout << "\n";
    }*/
    forn (i, 0, n)
        forn (j, 0, n)
            if (!ans[i][j])
                return cout << "NO", 0;
    cout << "YES\n";
    forn (i, 0, n) {
        forn (j, 0, n)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}