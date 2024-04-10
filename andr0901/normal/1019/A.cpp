#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(m);
    forn (i, 0, n) {
        int p, c;
        cin >> p >> c, p--;
        a[p].pb(c);
    }
    forn (i, 0, m)
        sort(rall(a[i]));
    ll ans = 1e18;
    forn (i, 0, n) {
        auto b = a;
        ll cur = 0;
        int votes = sz(a[0]);
        forn (j, 1, m) {
            while (sz(b[j]) > i) {
                cur += b[j].back();
                votes++;
                b[j].pop_back();
            }
        }
        vector <int> other;
        forn (j, 1, m)
            for (int k : b[j])
                other.pb(k);
        if (votes + sz(other) <= i)
            continue;
        sort(rall(other));
        while (votes <= i) {
            cur += other.back();
            votes++;
            other.pop_back();
        }
        ans = min(ans, cur);
    }
    cout << ans;
    return 0;
}