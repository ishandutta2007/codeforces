#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <ll> suf(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    reverse(all(s));
    reverse(all(a));
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans = max(ans, cur + (i < n - 1 ? suf[i + 1] : 0));
            cur += a[i];
        } 
    }
    ans = max(ans, cur);
    printf("%lld\n", ans);
}