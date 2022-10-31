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
    while (q -- > 0) {
        int n;
        cin >> n;
        vector <int> a(3);
        forn (i, 0, n) {
            int t;
            cin >> t;
            a[t % 3]++;
        }
        int ans = min(a[1], a[2]);
        a[1] -= ans, a[2] -= ans;
        cout << a[0] + a[1] / 3 + a[2] / 3 + ans << "\n";
    }
    return 0;
}