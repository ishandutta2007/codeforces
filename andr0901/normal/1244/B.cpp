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
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector <char> a(n);
        forn (i, 0, n) 
            cin >> a[i];
        int mx = -1;
        forn (i, 0, n)
            if (a[i] == '1')
                mx = i;
        int mn = n + 1;
        for (int i = n - 1; i >= 0; i--)
            if (a[i] == '1')
                mn = i;
        if (mx == -1) {
            cout << n;
        } else {
            cout << 2 * (n - min(mn, n - mx - 1));
        }
        cout << "\n";
    }
    return 0;
}