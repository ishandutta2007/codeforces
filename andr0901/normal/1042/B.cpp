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

const int INF = 1e9;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(1 << 3, INF);
    forn (i, 0, n) {
        int t;
        string s;
        cin >> t >> s;
        sort(all(s));
        int mask = 0;
        for (auto j : s)
            mask |= (1 << (j - 'A'));
        a[mask] = min(a[mask], t);
    }
    forn (i, 0, (1 << 3)) {
        forn (j, 0, (1 << 3)) {
            forn (k, 0, (1 << 3)) {
                if ((j | k) != i)
                    continue;
                a[i] = min(a[i], a[j] + a[k]);
            }
        }
    }
    if (a[7] == INF)
        cout << -1;
    else 
        cout << a[7];
    return 0;
}