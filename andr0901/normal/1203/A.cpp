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

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    forn (i, 0, n) 
        a.pb(a[i]); {
        bool ok = 1;
        forn (i, 0, n) {
            if (a[i] == 1) {
                forn (j, 0, n) {
                    if (a[i + j] != 1 + j) {
                        ok = 0;
                    }
                }
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    } 
    reverse(all(a)); {
        bool ok = 1;
        forn (i, 0, n) {
            if (a[i] == 1) {
                forn (j, 0, n) {
                    if (a[i + j] != 1 + j) {
                        ok = 0;
                    }
                }
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0)
        solve();
    return 0;
}