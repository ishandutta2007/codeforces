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
        int n, m;
        cin >> n;
        vector <int> a(2);
        forn (i, 0, n) {
            int x;
            cin >> x;
            a[x % 2]++;
        }
        cin >> m;
        vector <int> b(2);
        forn (i, 0, m) {
            int x;
            cin >> x;
            b[x % 2]++;
        }
        cout << (1LL * a[0] * b[0] + 1LL * a[1] * b[1]) << "\n";
    }
    return 0;
}