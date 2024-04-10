#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

typedef long long ll;

main() {
    int n, q;
    cin >> n >> q;
    vector <pii> a(q);
    vector <int> b(n);
    forn (i, 0, q) {
        cin >> a[i].fs >> a[i].sc;
        a[i].fs--;
        forn (j, a[i].fs, a[i].sc)
            b[j]++;
    }
    int ans = 0;
    forn (i, 0, q) {
        forn (j, a[i].fs, a[i].sc)
            b[j]--;
        vector <int> s;
        forn (j, 0, n)
            if (b[j] == 1)
                s.pb(j);
        int cur = 0;
        forn (j, 0, n)
            if (b[j])
                cur++;
        //cout << cur << " ";
        forn (j, i + 1, q)
            ans = max(ans, cur - (lower_bound(all(s), a[j].sc) - lower_bound(all(s), a[j].fs)));
        forn (j, a[i].fs, a[i].sc)
            b[j]++;
    }
    cout << ans;
    return 0;
}