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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

bool check(int x, int y, const vector <vector <int>>& a) {
    return a[x][y] > a[x - 1][y] && a[x][y] > a[x][y - 1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n + 1, vector <int> (m + 1));
    auto b = a;
    forn (i, 1, n + 1)
        forn (j, 1, m + 1)
            cin >> a[i][j];
    forn (i, 1, n + 1)
        forn (j, 1, m + 1)
            cin >> b[i][j];
    forn (i, 1, n + 1) {
        forn (j, 1, m + 1) {
            int t1 = min(a[i][j], b[i][j]), t2 = max(a[i][j], b[i][j]);
            a[i][j] = t1, b[i][j] = t2;
        }
    }
    forn (i, 1, n + 1) 
        forn (j, 1, m + 1)
            if (!check(i, j, a) || !check(i, j, b))
                return cout << "Impossible", 0;
    cout << "Possible";
    return 0;
}