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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pii m = {-1, -1};
    forn (i, 0, n) {
        char type;
        cin >> type;
        if (type == '+') {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            m.fs = max(m.fs, x);
            m.sc = max(m.sc, y);
        } else {
            int h, w;
            cin >> h >> w;
            if (h > w)
                swap(h, w);
            if (h >= m.fs && w >= m.sc)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}