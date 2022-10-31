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
#define int long long

int n;
double t;
vector <vector <pair <int, pii>>> b;

bool cmp(pair <int, pii> a, pair <int, pii> b) {
    return a.fs < b.fs;
}

int get(vector <pair <int, pii>>& c, int x) {
    int l = 0, r = sz(c);
    while (r - l > 1) {
        int m = r + l >> 1;
        if (c[m].fs <= x)
            l = m;
        else 
            r = m;
    }
    return l;
}

void go(int i, int prev, vector <int>& a) {
    if (i >= n) {
        cout << "Yes\n";
        forn (i, 0, sz(a))
            cout << a[i] << " ";
        exit(0);
    }   
    if (clock() - t > 1.95 * CLOCKS_PER_SEC)
        cout << "No", exit(0);
    int t = get(b[a[i + 1]], a[i] - prev);
    forn (j, t, sz(b[a[i + 1]])) {
        int v = b[a[i + 1]][j].sc.fs, u = b[a[i + 1]][j].sc.sc;
        if ((v - u) * (v - u) / 4 - prev <= 0)
             continue;
        a[i] = (v - u) * (v - u) / 4 - prev;
        go(i + 2, (v + u) * (v + u) / 4, a);
    }
}

mt19937 rnd(228);

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    t = clock();
    cin >> n;
    vector <int> a(n);
    for (int i = 1; i < n; i += 2)
        cin >> a[i];
    b.resize(2e5 + 10);
    for (int i = 0; i <= sz(b); i++) {
        for (int j = 1; j * j <= i; j++) 
            if (i % j == 0 && j % 2 == (i / j) % 2) 
                b[i].pb({(j - i / j) * (j - i / j) / 4, {j, i / j}});
        sort(all(b[i]), cmp);
    }
    go(0, 0, a);
    cout << "No";
    return 0;
}