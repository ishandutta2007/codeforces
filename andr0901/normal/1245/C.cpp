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
    string s;
    cin >> s;
    s += '#';
    vector <int> f(sz(s) + 1, 1);
    const int MOD = 1e9 + 7;
    forn (i, 2, sz(s) + 1)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    ll ans = 1;
    int U = 0, W = 0;
    forn (i, 0, sz(s)) {
        if (s[i] == 'm' || s[i] == 'w')
            return cout << 0, 0;
        if (s[i] != 'u') {
            ans = (1LL * ans * f[i - U]) % MOD;
            U = i + 1;
        }
        if (s[i] != 'n') {
            ans = (1LL * ans * f[i - W]) % MOD;
            W = i + 1;
        }
        //cout << U << " " << W << "\n";
    }
    cout << ans;
    return 0;
}