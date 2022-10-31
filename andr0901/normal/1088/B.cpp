#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define int long long

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> b(n);
    forn (i, 0, n)
        cin >> b[i];
    b.pb(-1);
    sort (b.begin(), b.end());
    vector <int> a;
    forn (i, 1, n + 1)
        if (b[i] != b[i - 1])
            a.pb(b[i]);
    int s = 0;
    forn (i, 0, k) {
        if (i >= a.size()) {
            forn (j, i, k)
                cout << "0\n";
            return 0;
        }
        if (a[i] - s == 0) {
            forn (j, i, k)
                cout << "0\n";
            return 0;
        }
        cout << a[i] - s << "\n";
        s += a[i] - s;
    }
    return 0;
}