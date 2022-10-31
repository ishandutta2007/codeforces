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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    int j = k, m = 0;
    vector <vector <int>> b;
    forn (i, 0, min(n, k))
        b.pb({a[i], a[i], i});
    vector <bool> ans(n);
    while (b.size()) {
        vector <vector <int>> new_bb;
        for (auto i : b) {
            if (i[0])
                new_bb.pb(i);
            else
                m++;
        }
        b = new_bb;
        while (j < n && b.size() < k)
            b.pb({a[j], a[j], j++});
        forn (i, 0, b.size())
            b[i][0]--;
        for (auto i : b)
            if ((int)(round(100.0 * m / n)) == i[1] - i[0])
                ans[i[2]] = 1;
    }
    int cnt = 0;
    forn (i, 0, n)
        cnt += ans[i];
    cout << cnt;
    return 0;
}