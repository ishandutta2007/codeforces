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

vector <vector <char>> a;
vector <int> c;
int n, m;
int sx, sy, ex, ey;

vector <pii> b = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool is_on_field(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m && a[x][y] != '#');
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    a.resize(n, vector <char> (m));
    forn (i, 0, n) {
        forn (j, 0, m) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    char t;
    while (cin >> t)
        c.pb(t - '0');
    sort(all(b));
    int ans = 0;
    do {
        int x = sx, y = sy;
        //cout << b[0].fs;
        forn (i, 0, c.size()) {
            //cout << c[i];
            //cout << x << " " << x + b[c[i]].fs << " " << y << " " << b[c[i]].sc << "\n";
            if (!is_on_field(x + b[c[i]].fs, y + b[c[i]].sc))
                break;
            x += b[c[i]].fs, y += b[c[i]].sc;
            if (x == ex && y == ey) {
                ans++;
                break;
            }
        }
    } while (next_permutation(all(b)));
    cout << ans;
    return 0;
}