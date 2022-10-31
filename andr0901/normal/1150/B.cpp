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

vector <vector <char>> a;

bool check(int x, int y) {
    return a[x][y] == '.' && a[x + 1][y] == '.' && a[x - 1][y] == '.' && a[x][y - 1] == '.' && a[x][y + 1] == '.';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n, vector <char> (n));
    forn (i, 0, n)
        forn (j, 0, n) 
            cin >> a[i][j];
    forn (i, 1, n - 1) 
        forn (j, 1, n - 1) 
            if (a[i][j] == '.')
                if (check(i, j)) 
                    a[i][j] = '#', a[i + 1][j] = '#', a[i - 1][j] = '#', a[i][j - 1] = '#', a[i][j + 1] = '#';
    forn (i, 0, n)
        forn (j, 0, n)
            if (a[i][j] == '.')
                return cout << "NO", 0;
    cout << "YES";
    return 0;
}