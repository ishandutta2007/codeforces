#pragma GCC optimize("Ofast")
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
    int q;
    cin >> q;
    while (q --> 0) {
        ll n;
        cin >> n;
        int ans = 0, ok = 1;
        while (n != 1) {
            if (n % 5 == 0)
                n = 4 * n / 5;
            else if (n % 3 == 0)
                n = 2 * n / 3;
            else if (n % 2 == 0)
                n = n / 2;
            else {
                ok = 0;
                break;
            }
            ans++;
        }
        if (ok)
            cout << ans;
        else 
            cout << -1;
        cout << "\n";
    }
    return 0;
}