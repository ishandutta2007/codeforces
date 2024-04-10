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
    vector <ll> a(2 * n);
    forn (i, 0, 2 * n) 
        cin >> a[i];
    sort(all(a));
    ll sum1 = 0, sum2 = 0;
    forn (i, 0, n) 
        sum1 += a[i];
    forn (i, n, 2 * n)
        sum2 += a[i];
    if (sum1 == sum2)
        return cout << -1, 0;
    forn (i, 0, 2 * n)
        cout << a[i] << " ";
    return 0;
}