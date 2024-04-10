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
    int n, m;
    cin >> n >> m;
    vector <vector <int>> gr(n);
    forn (i, 0, m) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        gr[t1].pb(t2), gr[t2].pb(t1);
    }
    set <int> s;
    vector <bool> used(n);
    s.insert(0), used[0] = 1;
    forn (i, 0, n) {
        int t = *s.begin();
        cout << t + 1 << " ";
        used[t] = 1;
        s.erase(t);
        for (auto j : gr[t])
            if (!used[j])
                s.insert(j);
    }
    return 0;
}