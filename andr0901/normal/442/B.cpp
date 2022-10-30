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
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector <long double> a(n);
    forn (i, 0, n)
        cin >> a[i];
    sort(rall(a));
    long double ans = 0;
    forn (i, 0, n) {
        if (a[i] == 1)
            return cout << 1, 0;
        long double sum = 1;
        forn (j, 0, i + 1)
            sum *= (1 - a[j]);
        long double cur = 0;
        forn (j, 0, i + 1)
            cur += a[j] * (sum / (1 - a[j]));
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}