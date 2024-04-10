#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long
#define int long long

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    ll s = 0;
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = i + 1;
        s += a[i].fs;
    }
    sort(a.begin(), a.end());
    vector <int> ans;
    forn (i, 0, n - 1) {
        if (2 * a[n - 1].fs == s - a[i].fs)
            ans.push_back(a[i].sc);
    }
    if (2 * a[n - 2].fs == s - a[n - 1].fs)
        ans.push_back(a[n - 1].sc);
    cout << ans.size() << "\n";
    forn (i, 0, ans.size())
        cout << ans[i] << " ";
    return 0;
}