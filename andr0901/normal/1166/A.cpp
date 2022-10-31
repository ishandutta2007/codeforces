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
    vector <int> a(26), b(26), c(26);
    forn (i, 0, n) {
        string s;
        cin >> s;
        if (c[s[0] - 'a']) 
            a[s[0] - 'a']++;
        else 
            b[s[0] - 'a']++;
        c[s[0] - 'a'] ^= 1;
    }
    int ans = 0;
    forn (i, 0, 26)
        ans += a[i] * (a[i] - 1) / 2 + b[i] * (b[i] - 1) / 2;
    cout << ans;

    return 0;
}