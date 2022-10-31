#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    int x = 0;
    forn (i, 0, sz(b)) 
        x += (b[i] == '1');
    vector <int> pref(sz(a) + 1);
    forn (i, 0, sz(a))
        pref[i + 1] = pref[i] + (a[i] == '1');
    int ans = 0;
    forn (i, 0, sz(a) - sz(b) + 1)
        ans += (pref[i + sz(b)] - pref[i]) % 2 == x % 2;
    cout << ans;
    return 0;
}