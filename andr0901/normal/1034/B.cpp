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

map <pii, pii> mt;
map <pii, vector <pii>> gr;
map <pii, bool> used;

int dst(pii a, pii b) {
    return abs(a.fs - b.fs) + abs(a.sc - b.sc);
}

bool dfs(pii v) {
    if (used[v])
        return 0;
    used[v] = 1;
    for (pii u : gr[v]) {
        if (mt[u].fs == -1 || dfs(mt[u])) {
            mt[u] = v;
            return 1;
        }
    }
    return 0;
}

void stress() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    forn (n, 1, 20) {
        forn (m, 1, 20) {
            gr.clear();
            forn (i1, 0, n) 
                forn (j1, 0, m) 
                    forn (i2, 0, n) 
                        forn (j2, 0, m) 
                            if ((i1 + j1) % 2 && dst({i1, j1}, {i2, j2}) == 3)
                                gr[{i1, j1}].eb(i2, j2);
            mt.clear();
            forn (i, 0, n) 
                forn (j, 0, m) 
                    mt[{i, j}] = {-1, -1};
            int ans = 0;
            forn (i, 0, n) {
                forn (j, 0, m) {
                    if ((i + j) % 2) {
                        used.clear();
                        ans += dfs({i, j});
                    }
                }
            }
            cout << n << " " << m << ": " << 2 * ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    //stress();
    ll n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    if (n == 1) {
        if (m % 6 <= 3)
            cout << (m / 6) * 6;
        else 
            cout << (m / 6) * 6 + (m % 6 - 3) * 2;
        return 0;
    }
    if (n == 2) {
        if (m == 2)
            cout << 0;
        else if (m == 1 || m == 3 || m == 7)
            cout << n * m - 2;
        else 
            cout << n * m;
        return 0;
    }
    if (n % 2 && m % 2)
        cout << n * m - 1;
    else 
        cout << n * m;
    return 0;
}