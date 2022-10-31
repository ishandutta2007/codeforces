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
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <char> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    vector <char> p = {'R', 'G', 'B'};
    sort(all(p));
    vector <char> ans;
    int ans_diff = 1e9;
    do {
        int cur = 0;
        forn (i, 0, n) 
            cur += (p[i % 3] != a[i]);
        if (cur < ans_diff) {
            ans_diff = cur;
            ans = p;
        }
    } while (next_permutation(all(p)));
    cout << ans_diff << "\n";
    forn (i, 0, n) 
        cout << ans[i % 3];
    return 0;
}