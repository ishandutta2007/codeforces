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

vector <vector <bool>> a;
int n;

int check(int idx) {
    forn (i, 0, n / idx) {
        forn (j, 0, n / idx) {
            char t = a[i * idx][j * idx];
            forn (k, 0, idx) {
                forn (l, 0, idx) {
                    if (a[i * idx + k][j * idx + l] != t)
                        return 0;
                }
            }
        }
    }
    return idx;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    a.resize(n, vector <bool> (n));
    forn (i, 0, n) {
        forn (j, 0, n / 4) {
            char c;
            cin >> c;
            if ('A' <= c && c <= 'Z')
                c = c - 'A' + 10;
            else
                c -= '0';
            //cout << (int)c << " ";
            for (int k = 3; k >= 0; k--)  {
                a[i][4 * j + k] = c % 2;
                c /= 2;
            }
        }
        //cout << "\n";
    }
    /*forn (i, 0, n) {
        forn (j, 0, n)
            cout << a[i][j];
        cout << "\n";
    }*/
    int ans = 1;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = max({ans, check(i), check(n / i)});
        }
    }
    cout << ans;
    return 0;
}