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

vector <ll> pr;
ll t;

ll solve(int l, int r) {
    if (r - l == 1)
        return 0;
    int m = l + r >> 1;
    ll ans = solve(l, m) + solve(m, r);
    vector <ll> a;
    forn (i, l, m)
        a.pb(pr[i]);
    sort(all(a));
    forn (i, m, r) 
        ans += (sz(a) - (upper_bound(all(a), pr[i] - t) - a.begin()));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> t;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    pr.resize(n + 1);
    forn (i, 0, n)
        pr[i + 1] = pr[i] + a[i];
    cout << solve(0, n + 1);
    return 0;
}