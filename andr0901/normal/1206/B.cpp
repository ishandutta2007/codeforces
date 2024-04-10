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
    int n;
    cin >> n;
    vector <int> a(n);
    bool zero = 0;
    ll ans = 0;
    forn (i, 0, n) {
        cin >> a[i];
        ans += min(abs(a[i] - 1), abs(a[i] + 1));
        if (!a[i])
            zero = 1;
    }
    if (zero) 
        cout << ans;
    else {
        int sign = 1;
        forn (i, 0, n) 
            if (a[i] < 0)
                sign *= -1;
        if (sign == -1) 
            cout << ans + 2;
        else 
            cout << ans;
    }
    return 0;
}