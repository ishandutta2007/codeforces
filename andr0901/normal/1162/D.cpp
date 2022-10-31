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
#define eb emplace_back

int n, m;

int dst(int a, int b) {
    return (a - b + 2 * n) % n;
}
vector <pii> a;

bool check(int j) {
    if (j == n)
        return 0;
    vector <pii> b;
    forn (i, 0, sz(a))
        b.eb((a[i].fs + j) % n, (a[i].sc + j) % n);
    sort(all(b));
    forn (i, 0, sz(a))
        if (b[i].fs != a[i].fs || b[i].sc != a[i].sc)
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        if (dst(v, u) > n / 2)
            swap(v, u);
        if (n % 2 == 0 && dst(v, u) == n / 2)
            a.eb(v, u), a.eb(u, v);
        else 
            a.eb(v, u);
    }
    sort(all(a));
    /*forn (i, 0, sz(a)) {
        cout << i << ":  ";
        for (auto j : a[i])
            cout << j << " ";
        cout << "\n";
    }*/
    for (int j = 1; j * j <= n; j++) {
        if (n % j)
            continue;
        if (check(j))
            return cout << "Yes", 0;
        if (check(n / j))
            return cout << "Yes", 0;
    }
    cout << "No";
    return 0; 
}