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
    int n, k;
    cin >> n >> k;
    vector <pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = i;
    }
    sort(all(a));
    vector <set <int>> b(k);
    vector <int> ans(n);
    int j = 0;
    forn (i, 0, k) {
        b[i].insert(a[i].fs);
        ans[a[i].sc] = i;
    }
    forn (i, k, n) {
        bool f = 1;
        forn (j, 0, k) {
            if (b[j].find(a[i].fs) == b[j].end()) {
                b[j].insert(a[i].fs);
                ans[a[i].sc] = j;
                f = 0;
                break;
            }
        }
        if (f)
            return cout << "NO", 0;
    }
    cout << "YES\n";
    forn (i, 0, n)
        cout << ans[i] + 1 << " ";
    return 0;
}