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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    forn (i, 0, n)  
        cin >> a[i];
    deque <int> suf(n + 1);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];
    int ans = suf[0];
    suf.pop_back(), suf.pop_front();
    sort(rall(suf));
    forn (i, 0, k - 1)
        ans += suf[i];
    cout << ans;
    return 0;
}