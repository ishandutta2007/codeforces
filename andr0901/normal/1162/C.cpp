#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> first(n, 1e9);
    vector <set <int>> a(n);
    forn (i, 0, k) {
        int t;
        cin >> t;
        t--;
        if (first[t] == 1e9)
            first[t] = i;
        a[t].insert(i);
    }
    int ans = 0;
    forn (i, 0, n) {
        int j = first[i];
        if (j == 1e9) 
            ans++;
        int l = i - 1, r = i + 1;
        if (l >= 0) {
            if (j == 1e9 || a[l].lower_bound(j + 1) == a[l].end())
                ans++;
        }
        if (r < n) {
            if (j == 1e9 || a[r].lower_bound(j + 1) == a[r].end())
                ans++;
        }
    }
    cout << ans;
    return 0;
}