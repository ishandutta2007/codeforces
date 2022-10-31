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
    vector <ll> a(n / 2);
    forn (i, 0, n / 2)
        cin >> a[i];
    vector <ll> b(n);
    forn (i, 0, n / 2) {
        if (!i) {
            b[i] = 0, b[n - i - 1] = a[i];
            continue;
        }
        b[i] = max(b[i - 1], a[i] - b[n - i]);
        b[n - i - 1] = a[i] - b[i];
    }
    forn (i, 0, n)
        cout << b[i] << " ";
    return 0;
}