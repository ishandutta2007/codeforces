#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    string s;
    cin >> s;
    vector <int> a(sz(s) + 1);
    forn (i, 0, sz(s)) {
        if (i == 0 || s[i] == 'o' || (s[i] == 'v' &&  s[i - 1] == 'o'))
            a[i + 1] = a[i];
        else 
            a[i + 1] = a[i] + 1;
    }
    vector <int> b(sz(s) + 1);
    forn (i, sz(s), 0) {
        if (i == sz(s) - 1 || s[i] == 'o' || (s[i] == 'v' && s[i + 1] == 'o'))
            b[i] = b[i + 1];
        else 
            b[i] = b[i + 1] + 1;
    }
    ll ans = 0;
    forn (i, 0, sz(s)) 
        if (s[i] == 'o') 
            ans += 1LL * a[i] * b[i];
    cout << ans;
    return 0;
}