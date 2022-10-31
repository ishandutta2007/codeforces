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

int n;
vector <int> a;

void go(vector <int> b) {
    if (b.size() == n) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += b[i] * a[i];
        }
        // cout << s << " ";
        if (s % 360 == 0) {
            cout << "YES";
            exit(0);
        }
        return;
    }
    b.push_back(1);
    go(b);
    b.pop_back();
    b.push_back(-1);
    go(b);
}

main() {
   // ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    a.resize(n);
    int s = 0;
    forn (i, 0, n)
        cin >> a[i];
    go({});
    cout << "NO";
    /*forn (i, 0, n) {
        if ((s - a[i] + 360 * 100) % 360 == a[i] % 360)
            return cout << "YES", 0;
    }
    cout << "NO";*/
    return 0;
}