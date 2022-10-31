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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    long double n, s;
    cin >> n >> s;
    vector <vector <int>> gr(n);
    forn (i, 1, n) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        gr[t1].pb(t2);
        gr[t2].pb(t1);
    }
    long double m = 0, cnt = 0;
    forn (i, 0, n) {
        if ((int)gr[i].size() == 1) {
            m++;
        }
        //cout << gr[i].size() << "\n";
    }
    //cout << m << " " << cnt;
    cout << fixed << setprecision(20) << 2.0 * s / m;
    return 0;
}