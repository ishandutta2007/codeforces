#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long
#define int long long

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    vector <int> a(n + 2);
    forn (i, 1, n + 1) {
        cin >> a[i];
    }
    a[0] = a[n + 1] = -1;
    int cur = 0;
    forn (i, 1, n + 1) {
        if (a[i] > l && a[i + 1] <= l)
            cur++;
    }
    while (m --> 0) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << cur << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            if (a[x] <= l && a[x] + y > l) {
                if (a[x - 1] > l && a[x + 1] > l)
                    cur--;
                if (a[x - 1] <= l && a[x + 1] <= l)
                    cur++;
            }
            a[x] += y;
        }
    }
    return 0;
}